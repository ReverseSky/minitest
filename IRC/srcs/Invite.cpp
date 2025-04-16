/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:38:39 by grobledo          #+#    #+#             */
/*   Updated: 2025/04/13 22:41:23 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

void Commands::handleInvite(std::string prefix, std::vector<std::string> param, std::string trailing, Client *client, Server *server)
{
	(void)prefix;
	(void)trailing;

	if (param.size() < 2) {
		server->reply(ERR_NEEDMOREPARAMS("INVITE"), client);
		return;
	}

	std::string targetNick = param[0];
	std::string channelname = param[1];

	Channel* channel = server->findChannel(channelname);
	if (!channel) {
		server->reply(ERR_NOSUCHCHANNEL(channelname), client);
		return;
	}

	if (!channel->hasUser(client->getNickname())) {
		server->reply(ERR_NOTONCHANNEL(channelname), client);
		return;
	}

	if (channel->hasMode('i') && !channel->isOperator(client->getFd())) {
		server->reply(ERR_CHANOPRIVSNEEDED(channelname), client);
		return;
	}

	Client* target = server->findClientByNick(targetNick);
	if (!target) {
		server->reply(ERR_NOSUCHNICK(channelname, targetNick), client);
		return;
	}

	if (channel->hasUser(target->getNickname())) {
		server->reply(ERR_USERONCHANNEL(targetNick, channelname), client);
		return;
	}

	if (channel->checkInvit(target->getNickname())) {
		server->reply(ERR_USERONINVLIST(targetNick, channelname), client);
		return;
	}

	channel->addInvit(target->getNickname());
	server->reply(RPL_INVITING(channelname, target->getNickname()), client);
	server->reply(RPL_INVITING(channelname, client->getNickname()), target);
}
