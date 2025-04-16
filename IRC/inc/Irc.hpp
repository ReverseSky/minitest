/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:03:55 by momillio          #+#    #+#             */
/*   Updated: 2025/04/10 21:01:07 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <csignal>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <map>
#include <sstream>
#include <netdb.h>
#include <exception>
#include <algorithm>
#include <set>


#include "color.h"
#include "Server.class.hpp"
#include "Client.class.hpp"
#include "Channel.class.hpp"
#include "Commands.hpp"
#include "ErrorResponse.hpp"
#include "CmdRresponse.hpp"
#include "Utils.hpp"

#define SUCCESS 0
#define FAILURE 1
#define MESS_MAX_LEN 512
#define BUFFER_SIZE	1024
#define MAX_QUEUE 10
#define MAX_CLIENTS 10
#define PASS_MAX_LEN 30
#define NICK_LEN 15
#define CRLF "\r\n"
#define SERVER_NAME "ft_irc 42"
#define VERSION "1.1"