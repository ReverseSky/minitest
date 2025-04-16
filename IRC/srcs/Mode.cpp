/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:49:35 by grobledo          #+#    #+#             */
/*   Updated: 2025/04/16 10:05:12 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

#include "../inc/Irc.hpp"

void Commands::handleMode(std::string prefix, std::vector<std::string> params, std::string trailing, Client* client, Server* server)
{
	(void)prefix;
	(void)trailing;

	if (params.size() < 2) {
		server->reply(ERR_NEEDMOREPARAMS("MODE"), client);
		return;
	}

	std::string channelName = params[0];
	std::string modeString = params[1];

	Channel* chan = server->findChannel(channelName);
	if (!chan) {
		server->reply(ERR_NOSUCHCHANNEL(channelName), client);
		return;
	}

	if (!chan->isOperator(client->getFd())) {
		server->reply(ERR_CHANOPRIVSNEEDED(channelName), client);
		return;
	}

	if (modeString.size() > 4) {
		server->reply(ERR_NEEDLESSPARAMS("MODE"), client);
	}
		
	char flag = modeString[0];
	if (flag != '+' && flag != '-') {
		server->reply(ERR_UNKNOWNMODE(modeString, channelName), client);
		return;
	}

	size_t paramIndex = 2;

	for (size_t i = 1; i < modeString.size(); ++i) {
		char mode = modeString[i];

		switch (mode) {

			case 'i':
			case 't':
				if (flag == '+')
					chan->setMode(mode);
				else
					chan->unsetMode(mode);
				break;

			case 'k':
				if (flag == '+') {
					if (paramIndex >= params.size()) {
						server->reply(ERR_NEEDMOREPARAMS("MODE +k"), client);
						return;
					}
					chan->setKey(params[paramIndex++]);
				} else {
					chan->unsetKey();
				}
				break;

			case 'l':
				if (flag == '+') {
					if (paramIndex >= params.size()) {
						server->reply(ERR_NEEDMOREPARAMS("MODE +l"), client);
						return;
					}
					size_t limit = std::atoi(params[paramIndex++].c_str());
					chan->setLimit(limit);
				} else {
					chan->unsetLimit();
				}
				break;

			case 'o':
				if (paramIndex >= params.size()) {
					server->reply(ERR_NEEDMOREPARAMS("MODE +o/-o"), client);
					return;
				}
				{
					Client* target = server->findClientByNick(params[paramIndex]);
					if (!target || !chan->hasUser(target->getNickname())) {
						server->reply(ERR_USERNOTINCHANNEL(params[paramIndex], channelName), client);
						return;
					}
					if (flag == '+')
						chan->addOperator(target->getFd());
					else if (flag == '-' && chan->getOperatorCount() == 1) {
						server->reply(ERR_LASTCHANOP(chan->getName(), target->getNickname()), client);
							return;
					}
					else
						chan->removeOperator(target->getFd());
					++paramIndex;
				}
				break;
			case 'b':
			{
				Client* target = server->findClientByNick(params[paramIndex]);
				if (paramIndex >= params.size()) {
					server->reply(ERR_NEEDMOREPARAMS("MODE +b/-b"), client);
					continue;
				}
				if (flag == '+') {
					if (!chan->checkBan(target->getNickname()))
						chan->isBan(target, server);
					}
				if (flag == '-') {
					if (chan->checkBan(target->getNickname()))
						chan->unban(target->getNickname());
				}
				
			}

			default:
				server->reply(ERR_UNKNOWNMODE(std::string(1, mode), channelName), client);
				break;
		}
	}
}

