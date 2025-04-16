/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerLoop.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momillio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:18:26 by momillio          #+#    #+#             */
/*   Updated: 2025/04/09 17:40:18 by momillio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

/*
	poll(struct pollfd *fds, nfds_t nfds, int timeout)
		- timeout :
			-> 0 = retour immédiat (non-bloquant)
			-> > 0 = attendre pendant la durée donnée
			-> -1 = attente infinie jusqu'à qu'un évènement se produise
	struct pollfd { int fd, short events, short revents}
		- fd : fd à surveiller
		- events : évènements à surveiller
		- revents : évènements détectés
			-> POLLIN = Données dispo en lecture
			-> POLLOUT = Prêt à écrire sans être bloqué
			-> POLLER = Erreur sur le fd
			-> POLLHUP = Déconnexion ou fermeture du fd
			-> POLLNVAL = fd invalide
		- return value :
			-> Nombre de fd prêts (> 0)
			-> 0 si le délai de timeout est écoulé sans évènements
			-> -1 en cas d'erreur (errno)
*/

int	Server::serverLoop()
{
	pollfd poll_srv;

	poll_srv.fd = _servSocketFd;
	poll_srv.events = POLLIN;
	poll_srv.revents = 0;

	_pollFds.push_back(poll_srv);

//	int i = -1;
	while (_signal == false) //_signal == false
	{
		for (pfd_iterator it = _pollFds.begin(); it != _pollFds.end(); it++)
			it->revents = 0;
		if (poll(_pollFds.data(), _pollFds.size(), -1) < 0)
		{
			std::cerr << "Error : error while polling" << std::endl;
			return FAILURE;
		}
			
		printPollTable();
		for (pfd_iterator it = _pollFds.begin(); it != _pollFds.end(); it++)
		{
//			std::cout << "Poll #" << it->fd << " Revents = " << it->revents << std::endl;
			if (it->revents == 0)
				continue ;
			if ((it->revents & POLLIN))
			{
					if (it->fd == _servSocketFd)
					{
						createConnection();
						break ;
					}
					else
					{
						readMessage(it->fd);
						break ;
					}

			}
//			std::cout << "Before pollout" << std::endl;
			if (it->revents & POLLOUT)
			{
//				std::cout << "IN POLLOUT" << std::endl;
				respondToClient(it->fd);
				break;
			}
			if ((it->revents & POLLHUP))
			{
				disconnectCLient(it->fd);
				break ;
			}
		}
//		printClientTable();
	}
	// close fds
	return SUCCESS;
}