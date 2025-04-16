/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:06:25 by grobledo          #+#    #+#             */
/*   Updated: 2025/04/11 17:12:26 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

void Commands::handleKick(std::string prefix, std::vector<std::string> param, std::string trailing, Client *client, Server *server)
{
	(void)prefix;
	(void)trailing;

	if (param.size() < 2) {
		server->reply(ERR_NEEDMOREPARAMS("KICK"), client);
		return;
	}

	std::vector<std::string> channels = split(param[0], ',');
	std::vector<std::string> users = split(param[1], ',');

	if (channels.size() > 1 && channels.size() != users.size())
		server->reply(ERR_NEEDMOREPARAMS("KICK"), client);

	for (size_t i = 0; i < users.size(); ++i) {
		std::string chanName;
		std::string targetNick = users[i];
		if (i <channels.size())
			chanName = channels[i];
		else
			chanName = channels.back();

		Channel* chan = server->findChannel(chanName);
		if (!chan) {
			server->reply(ERR_NOSUCHCHANNEL(chanName), client);
			continue;
		}

		if (!chan->hasUser(client->getNickname())) {
			server->reply(ERR_NOTONCHANNEL(chanName), client);
			continue;
		}

		if (!chan->isOperator(client->getFd())) {
			server->reply(ERR_CHANOPRIVSNEEDED(chanName), client);
			continue;
		}

		Client* target = server->findClientByNick(targetNick);
		if (!target || !chan->hasUser(target->getNickname())) {
			server->reply(ERR_USERNOTINCHANNEL(targetNick, chanName), client);
			continue;
		}

		std::string comment;
		if (trailing.empty())
			comment = client->getNickname();
		else
			comment = trailing;
		std::string kickMsg = ":" + client->getPrefix() + " KICK " + chanName + " " + targetNick + " :" + comment;

		chan->removeUser(target);
		server->reply(RPL_KICKMESSAGE(client->getPrefix(), chanName, targetNick, comment), target);
		server->reply(RPL_KICKSUCCESS(), client);
	}
}
