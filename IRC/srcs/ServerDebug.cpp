/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerDebug.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momillio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:41:17 by momillio          #+#    #+#             */
/*   Updated: 2025/04/03 16:12:25 by momillio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"


void	Server::printServInit()
{
	std::cout << "Serv socket = " << _servSocketFd << std::endl;
	std::cout << "Serv port  = " << _port << ", pass = " << _password << std::endl;
}

void	Server::printClientTable()
{
	if (_ClientTable.size() == 0)
		std::cout << "Client Table empty" << std::endl;
	std::cout << CYAN "CLIENT TABLE : "  << std::endl;
	for (client_iterator it = _ClientTable.begin(); it != _ClientTable.end(); it++)
		std::cout << "Client #" << it->second->getFd() << "\t";
	std::cout << RESET << std::endl;
}

void	Server::printPollTable()
{
	std::cout << YEL "POLL TABLE : "  << std::endl;
	for (pfd_iterator it = _pollFds.begin(); it != _pollFds.end(); it++)
		std::cout << "Poll #" << it->fd << "\t";
	std::cout << RESET << std::endl;
}