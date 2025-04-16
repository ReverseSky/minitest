/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momillio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:48:10 by momillio          #+#    #+#             */
/*   Updated: 2025/04/09 19:19:13 by momillio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

bool	isValidNick(std::string & nick)
{
	std::cout << nick << std::endl;
	if (std::isdigit(nick[0]))
		return false;
	else if (nick.find_first_of(" @!#:") != std::string::npos)
		return false;
	else if (nick.size() > 15)
		return false;
	return true;
}

void Commands::handleNick(std::string prefix, std::vector <std::string> param, std::string trailing, Client * client, Server *srv)
{
	(void)prefix;
	if (param.empty() || param[0].empty())
		srv->reply(ERR_NONICKNAMEGIVEN(), client);
	else if (param.size() > 1 || !trailing.empty())
		srv->reply(ERR_ERRORSYNTAXE("NICK"), client);
	else if (!isValidNick(param[0]))
		srv->reply(ERR_ERRONEUSNICKNAME(param[0]), client);
	else if (srv->getClient(param[0]))
		srv->reply(ERR_NICKNAMEINUSE(param[0]), client); 
	else
		client->setNickname(param[0]);
}