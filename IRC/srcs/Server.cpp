/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:05:32 by momillio          #+#    #+#             */
/*   Updated: 2025/04/10 19:46:57 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"


Server::~Server() 
{
	for (std::map<std::string, Channel*>::iterator it = _ChannelTable.begin(); it != _ChannelTable.end(); ++it) {
		delete it->second;
	}
	_ChannelTable.clear();
}

int	Server::serverInit(char *port)
{
	memset(&_hints, 0, sizeof(_hints));
	_hints.ai_family = AF_INET;
	_hints.ai_socktype = SOCK_STREAM;
	_hints.ai_flags = AI_PASSIVE;
	
	if (getaddrinfo(NULL, port, &_hints, &_infos) != 0)
	{
		std::cerr << "Error : failed to get infos" << std::endl;
		return FAILURE;
	}
	
	_servSocketFd = socket(AF_INET, SOCK_STREAM, 0);
	if (_servSocketFd < 0)
	{
		std::cerr << "Error : Failed to create socket" << std::endl;
		return FAILURE;
	}

	int optval = 1;
	
	if (setsockopt(_servSocketFd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		std::cerr << "Error : setsockopt failed" << std::endl;
		return FAILURE;
	}
	
	if (fcntl(_servSocketFd, F_SETFL, O_NONBLOCK) == -1)
	{
		std::cerr << "Error: setting socket_serv to non-blocking I/O failed" << std::endl;
		return FAILURE;
	}

	// Bind du socket
	if (bind(_servSocketFd, _infos->ai_addr, _infos->ai_addrlen) < 0)
	{
		std::cerr << "Error : Failed to bind socket" << std::endl;
		close (_servSocketFd);
		return FAILURE;
	}

	if (listen(_servSocketFd, MAX_CLIENTS) < 0) // écoute sur le port passé en paramètre et accepte max 3 connexions
	{
		std::cerr << "Error : listen failed" << std::endl;
		close (_servSocketFd);
		return FAILURE;
	}

	freeaddrinfo(_infos);
	std::cout << "Server listening on port " << _port << std::endl;
	return SUCCESS;
}

