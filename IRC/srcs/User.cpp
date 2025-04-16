/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:48:19 by momillio          #+#    #+#             */
/*   Updated: 2025/04/11 15:17:30 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

void Commands::handleUser(std::string prefix, std::vector<std::string> param, std::string trailing, Client * client, Server *srv)
{
	(void)srv;
	(void)prefix;
	std::cout <<"[" << trailing << "]" << std::endl;
	if (param.size() < 3 || trailing.empty())
	{
		srv->reply(ERR_NEEDMOREPARAMS("USER"), client);
		return ;
	}
	else if (client->getIsAuthentified())
	{
		srv->reply(ERR_ALREADYREGISTERED(), client);
		return ;
	}
	// tester si on rentre d'autres params que 0 et * la réponse
	client->setUsername(param[0]);
	client->setRealname(trailing);
}