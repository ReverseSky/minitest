/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:44:23 by momillio          #+#    #+#             */
/*   Updated: 2025/04/16 09:33:45 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Irc.hpp"


class Client;
class ParsedCommand;
class Commands;
class Channel;

class Server
{
	typedef std::vector<struct pollfd>::iterator		pfd_iterator;
	typedef std::map<int, Client *>::iterator			client_iterator;
	// typedef std::map<std::string, Channel *>::iterator	channel_iterator;
	
private:
	int 										_servSocketFd;
	int											_port;
	std::string 								_password;
	std::string									_time;
	struct addrinfo								_hints;
	struct addrinfo *							_infos;
	struct sockaddr_in							_clientAddr;
	
	std::map<int, Client *>						_ClientTable;
	std::map<std::string, Channel *>			_ChannelTable;
	std::vector<struct pollfd>	_pollFds;

	static bool									_signal;
	Server() {}
public:
	Server(std::string const & port, std::string const & password, struct tm * timeinfo);
	~Server();

	int					getPort() const;
	int 				getSocketFd() const;
	std::string const & getPassword() const;
	Client * 			getClient(std::string const & nickname);
	std::string			getTime();
	void	setPort(int port);
	void	setPassword(std::string password);
	void	setServSockedFd(int socket); 
	void	setTime(struct tm * timeinfo);

	int	serverInit(char  *port);
	int	serverLoop();
	int	createConnection();
	int	createClient(int fd);
	int	readMessage(int fd);
	void	disconnectCLient(int fd);
	static void	handeSignal(int signum);
	void	parseMessage(const std::string &line, Client * client);
	int	respondToClient(int fd);
//	void	reply(std::string const & msg, Client *client);
	void	sendRegistrationMsg(Client * client);
	void	reply(std::string const & msg, Client * client);
	
	void	printServInit();
	void	printClientTable();
	void	printPollTable();
	//return Channel* car peut etre nullptr si &Client null pas possible
	Channel*	findChannel(const std::string& name);
	Client*		findClientByNick(const std::string& nick);
	void		addChannel(const std::string& name, Channel* channel);
	void		removeChannel(const std::string &name);
	void		removeinvban(std::string nickname);
	//remove channel
};


