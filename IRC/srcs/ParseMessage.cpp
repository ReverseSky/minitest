/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseMessage.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:00:47 by grobledo          #+#    #+#             */
/*   Updated: 2025/04/13 22:21:52 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

static void	initCommandTable(std::map<std::string, void(*)(std::string, std::vector<std::string>, std::string, Client *, Server *)> & commandetable)
{
	commandetable["NICK"]    = Commands::handleNick;
	commandetable["USER"]    = Commands::handleUser;
	commandetable["JOIN"]    = Commands::handleJoin;
	commandetable["PRIVMSG"] = Commands::handlePrivmsg;
	commandetable["KICK"]    = Commands::handleKick;
	commandetable["INVITE"]  = Commands::handleInvite;
	commandetable["TOPIC"]   = Commands::handleTopic;
	commandetable["MODE"]    = Commands::handleMode;
	commandetable["PASS"]	 = Commands::handlePass;
}

static bool	isValidPrefix(const std::string& prefix) {
	if (prefix.empty())
		return true;

	// = npos si caractere pas trouve
	size_t excl = prefix.find('!');
	size_t at = prefix.find('@');

	// Cas 1 : nick!user@host
	if (excl != std::string::npos && at != std::string::npos && excl < at)
		return true;

	// Cas 2 : nick!user (sans host)
	if (excl != std::string::npos && at == std::string::npos)
		return true;

	// Cas 3 : nick@host (sans user)
	if (excl == std::string::npos && at != std::string::npos)
		return true;

	return true;
}

static int	parseCommand(std::string const & message, std::vector<std::string> & params, std::string & command, std::string & prefix, std::string & trailing)
{
	std::string buffer = message;
	std::string token;
	size_t pos = 0;

	std::cout << YEL "IN PARSE COMMAND" RESET << std::endl;
	// 1. Préfixe (commence par :)
	if (!buffer.empty() && buffer[0] == ':') {
		pos = buffer.find(' ');
		if (pos != std::string::npos) {
			prefix = buffer.substr(1, pos - 1);
		if (!isValidPrefix(prefix)) 
		{
			// a modifier avec bon code erreur
	//		senderror(ERR_NOPRIVILEGES(), client->getFd());
			return FAILURE;
		}
			buffer = buffer.substr(pos + 1);
		}
	}

	// 2. Trailing (commence par " :", tout ce qui suit est un bloc)
	pos = buffer.find(" :");
	if (pos != std::string::npos) {
		trailing = buffer.substr(pos + 2);
		buffer = buffer.substr(0, pos);
		trailing.erase(std::remove(trailing.begin(), trailing.end(), '\r'), trailing.end());
		trailing.erase(std::remove(trailing.begin(), trailing.end(), '\n'), trailing.end());
	}

	// 3. Commande + paramètres
	std::istringstream stream(buffer);
	bool first = true;
	while (stream >> token) {
		if (first) {
			command = token;
			first = false;
		} 
		else {
			params.push_back(token);
		}
	}
	return SUCCESS;
}

void Server::parseMessage(const std::string & message, Client *client) 
{
	std::vector<std::string> params;
	std::string command;
	std::string prefix;
	std::string trailing;

	std::cout << RED "IN PARSEMESSAGE" RESET << std::endl;
	if(parseCommand(message, params, command, prefix, trailing) == FAILURE)
		return;
	std::map<std::string, void(*)(std::string, std::vector<std::string>, std::string, Client *, Server *)> commandetable;
	
	initCommandTable(commandetable);
	std::cout << CYAN "AFTER PARSE COMMAND" RESET << std::endl;
	std::map<std::string, void(*)(std::string, std::vector<std::string>, std::string, Client *, Server *)>::iterator it = commandetable.find(command);
	if (it == commandetable.end())
		return;

	if (client->getIsAuthentified() == false)
	{
		if (client->getHasEnteredPass() == false)
		{
			if (command != "PASS")
			{
				this->reply("Error :Password required\r\n", client);
				return ;
			}
			it->second(prefix, params, trailing, client, this);
			return;
		}
		else if (command != "NICK" && command != "USER")
		{
			this->reply("Error :Nickname and username required\r\n", client);
			return ;
		}
		it->second(prefix, params, trailing, client, this);
		if (client->HasRequiredInfos())
			client->setIsAuthentified();			
		return;
	}
	else
		it->second(prefix, params, trailing, client, this);
}

