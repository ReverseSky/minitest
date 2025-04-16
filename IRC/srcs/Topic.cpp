/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:17:28 by grobledo          #+#    #+#             */
/*   Updated: 2025/04/11 17:26:02 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

void Commands::handleTopic(std::string prefix, std::vector<std::string> param, std::string trailing, Client* client, Server* server)
{
	(void)prefix;

	if (param.empty()) {
		server->reply(ERR_NEEDMOREPARAMS("TOPIC"), client);
		return;
	}

	std::string channelname = param[0];
	Channel* channel = server->findChannel(channelname);

	if (!channel) {
		server->reply(ERR_NOSUCHCHANNEL(channelname), client);
		return;
	}

	if (!channel->hasUser(client->getNickname())) {
		server->reply(ERR_NOTONCHANNEL(channelname), client);
		return;
	}

	// Affichage du topic si aucun trailing
	if (trailing.empty() && param.size() == 1) {
		std::string topic = channel->getTopic();
		if (topic.empty())
			server->reply(RPL_NOTOPIC(channelname), client);
		else
			server->reply(RPL_TOPIC(channelname, topic), client);
		return;
	}

	// Vérification du mode +t (seuls les opérateurs peuvent changer le topic)
	if (channel->hasMode('t') && !channel->isOperator(client->getFd())) {
		server->reply(ERR_CHANOPRIVSNEEDED(channelname), client);
		return;
	}

	// Modification du topic
	if (trailing.empty()) {
		channel->setTopic(""); // efface le topic
	} else {
		channel->setTopic(trailing);
	}
}

