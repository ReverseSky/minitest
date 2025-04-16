/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momillio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:47:48 by momillio          #+#    #+#             */
/*   Updated: 2025/04/09 19:17:12 by momillio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

void Commands::handlePass(std::string prefix, std::vector<std::string> params, std::string trailing, Client * client , Server *srv)
{
	(void)prefix;
	if (params.empty())
		srv->reply(ERR_NEEDMOREPARAMS("PASS"), client);
	else if (params.size() > 1 || !trailing.empty())
		srv->reply(ERR_ERRORSYNTAXE("PASS"), client);
	else if (client->getIsAuthentified())
		srv->reply(ERR_ALREADYREGISTERED(), client);
	else if (params[0] != srv->getPassword())
		srv->reply(ERR_PASSWDMISMATCH(), client);
	else
		client->setHasEnteredPass();
}