/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momillio <momillio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:01:27 by grobledo          #+#    #+#             */
/*   Updated: 2025/04/07 11:05:28 by momillio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Irc.hpp"

class Server;
class ParsedCommand;
class Client;

class Commands
{
public:
static void handleNick(std::string prefix, std::vector<std::string> params, std::string trailing, Client * client, Server *srv);
static void handleUser(std::string prefix, std::vector<std::string> params, std::string trailing, Client * client , Server *srv);
static void handleJoin(std::string prefix, std::vector<std::string> params, std::string trailing, Client * client , Server *srv);
static void handlePrivmsg(std::string prefix, std::vector<std::string> params, std::string trailing, Client * client , Server *srv);
static void handleKick(std::string prefix, std::vector<std::string> params, std::string trailing, Client * client , Server *srv);
static void handleInvite(std::string prefix, std::vector<std::string> params, std::string trailing, Client * client , Server *srv);
static void handleTopic(std::string prefix, std::vector<std::string> params, std::string trailing, Client * client , Server *srv);
static void handleMode(std::string prefix, std::vector<std::string> params, std::string trailing, Client * client , Server *srv);
static void handlePass(std::string prefix, std::vector<std::string> params, std::string trailing, Client * client , Server *srv);

private:

};