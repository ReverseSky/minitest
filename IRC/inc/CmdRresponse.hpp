/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdRresponse.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:14:29 by momillio          #+#    #+#             */
/*   Updated: 2025/04/13 22:13:44 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Irc.hpp"
	
	// Welcome messages
	#define RPL_WELCOME(nickname, username, hostname) (SERVER_NAME + std::string(":001 " + nickname + " :Welcome to the Internet Relay Network ") + nickname + "!" + username + "@" + hostname + CRLF)
	#define RPL_YOURHOST(nickname, servername, version) (SERVER_NAME + std::string(":002 " + nickname + " :Your host is ") + servername + ", running version " + version + CRLF)
	#define RPL_CREATED(nickname, creationdate) (SERVER_NAME + std::string(":003 " + nickname + " :This server was created ") + creationdate + CRLF)
	#define RPL_MYINFO(nickname, servername, version, usermode, channelmode) (SERVER_NAME + std::string(":004 " + nickname + " :") + servername + " " + version + " " + usermode + " " + channelmode + CRLF)
	
	// Channel modes
	#define RPL_CHANNELMODEIS(channelname, mode, modeparams) (std::string(":324 ") + channelname + " " + mode + " " + modeparams + CRLF)
	#define RPL_UNIQOPI(channelname, nickname) (std::string(":325 ") + channelname + " " + nickname + CRLF)
	#define RPL_NOTOPIC(channelname) (std::string(":331 ") + channelname + " :No topic is set" + CRLF)
	#define RPL_TOPIC(channelname, topic) (std::string(":332 ") + channelname + " :" + topic + CRLF)
	#define RPL_INVITING(channelname, nickname) (std::string(":341 ") + channelname + " " + nickname + CRLF)
	#define RPL_INVITELIST(channelname, invitemask) (std::string(":346 ") + channelname + " " + invitemask + CRLF)
	#define RPL_ENDOFINVITELIST(channelname) (std::string(":347 ") + channelname + " :End of channel invite list" + CRLF)
	#define RPL_BANLIST(channelname, banmask) (std::string(":367 ") + channelname + " " + banmask + CRLF)
	#define RPL_ENDOFBANLIST(channelname) (std::string(":368 ") + channelname + " :End of channel ban list" + CRLF)
	
	// MOTD replies
	#define RPL_MOTDSTART(servername) (std::string(":375 :- ") + servername + " message of the day" + CRLF)
	#define RPL_MOTD(text) (std::string(":372 :- ") + text + CRLF)
	#define RPL_ENDOFMOTD() (std::string(":376 :End of MOTD command") + CRLF)
	
	// Operator
	#define RPL_YOUREOPER() (std::string(":381 :You are now an IRC operator") + CRLF)
	
	// Retry
	#define RPL_TRYAGAIN(command) (std::string(":263 ") + command + " :Please wait a while and try again" + CRLF)
	
	//Test
	#define RPL_JOINSUCCESS() (std::string(" :You succefully joined a channel") + CRLF)
	#define RPL_KICKSUCCESS() (std::string(" :You succefully kicked user") + CRLF)
	#define RPL_CREATESUCCESS() (std::string(" :You succefully created a channel") + CRLF)
	#define RPL_NAMREPLY(channelname, userlist) (std::string(channelname) + " :" + std::string(userlist) + std::string(CRLF))
	#define RPL_ENDOFNAMES(channelname) (std::string(":") + channelname + " :End of NAMES list" + CRLF)
	#define RPL_KICKMESSAGE(prefix, channelname, targetnick, comment) (std::string(":") + prefix + " KICK " + channelname + " " + targetnick + " :" + comment + "\r\n")