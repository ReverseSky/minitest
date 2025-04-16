/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:20:56 by momillio          #+#    #+#             */
/*   Updated: 2025/04/10 19:51:01 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Irc.hpp"

bool	validPort(std::string port)
{
	if (port.find_first_not_of("0123456789") != std::string::npos)
		return false;
	int nb = atoi(port.c_str());
	if (nb <= 1023 || nb > 65535)
		return false;
	return true;
}

int main(int argc, char ** argv)
{
	if (argc != 3)
	{
		std::cout << "Usage : ./irc <port> <password>" << std::endl;
		return 1;
	}
	if (!validPort(argv[1]) || std::strlen(argv[2]) > PASS_MAX_LEN)
	{
		std::cerr << "Invalid port / password" << std::endl;
		return FAILURE;
	}

	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	Server	server(argv[1], argv[2], timeinfo);
	if (server.serverInit(argv[1]) == FAILURE)
		return FAILURE;
	server.printServInit();
	try
	{
		signal(SIGINT, Server::handeSignal);
		signal(SIGQUIT, Server::handeSignal);
		signal(SIGPIPE, SIG_IGN);
		server.serverLoop();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}