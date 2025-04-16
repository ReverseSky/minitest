/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:03:54 by grobledo          #+#    #+#             */
/*   Updated: 2025/04/13 22:57:49 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

//manque message a tous les clients du channels 
//RPL_NAMREPLY (353) → liste des utilisateurs
//RPL_ENDOFNAMES (366) → fin de la liste
//gestion operator
void Commands::handleJoin(std::string prefix, std::vector<std::string> params, std::string trailing, Client *client, Server *server) \
{
	(void) trailing;
	(void) prefix;

	if (params.empty()) {
		server->reply(ERR_NEEDMOREPARAMS("JOIN"), client);
		return;
	}

	if (params[0] == "0") {
		client->leaveAllChannels(server);
		return;
	}

	std::vector<std::string> channelNames = split(params[0], ',');
	std::vector<std::string> keys;
	if (params.size() > 1)
		keys = split(params[1], ',');

	for (size_t i = 0; i < channelNames.size(); ++i) {
		std::string channelName = channelNames[i];
		std::string key;

		if (i < key.size())
			key = keys[i];
		else
			key = "";

		if (!Channel::isNameValid(channelName)) {
			server->reply(ERR_BADCHANMASK(channelName), client);
			continue;
		}

		Channel* chan = server->findChannel(channelName);
		bool isNew = false;
		if (!chan) {
			chan = new Channel(channelName, key);
			server->addChannel(channelName, chan);
			isNew = true;
		}

		if (chan->checkBan(client->getNickname())) {
			server->reply(ERR_BANNEDFROMCHAN(channelName), client);
			continue;
		}

		if (chan->hasMode('i') && !chan->checkInvit(client->getNickname())) {
			server->reply(ERR_INVITEONLYCHAN(chan->getName()), client);
			continue;
		}

		if (chan->hasUser(client->getNickname())) {
			server->reply(ERR_USERONCHANNEL(client->getNickname(), channelName), client);
			continue;
		}

		if (chan->hasMode('l') && chan->getMemberListCount() >= chan->getLimit() && !chan->checkInvit(client->getNickname())) {
			server->reply(ERR_CHANNELISFULL(channelName), client);
			std::cout << "limit = " << chan->getLimit() << std::endl;
			continue;
		}

		if (!chan->checkKey(key)) {
			server->reply(ERR_BADCHANNELKEY(channelName), client);
			continue;
		}

		chan->addUser(client, server);
		client->joinChannel(chan, server);

		// Si premier utilisateur, opérateur
		if (chan->getUsers().size() == 1)
			chan->addOperator(client->getFd());

		if (isNew == true)
			server->reply(RPL_CREATESUCCESS(), client);
		else
		{
			server->reply(RPL_JOINSUCCESS(), client);
			server->reply(RPL_TOPIC(chan->getName(), chan->getTopic()), client);
			server->reply(RPL_NAMREPLY(chan->getName(), chan->getUsers()), client);
			server->reply(RPL_ENDOFNAMES(chan->getName()), client);
		}
		std::cout << "user" << chan->getUsers() << std::endl;
		if (chan->checkInvit(client->getNickname()))
			chan->removeInvit(client->getNickname());
	}
}
