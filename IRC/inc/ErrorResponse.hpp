/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorResponse.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:23:17 by momillio          #+#    #+#             */
/*   Updated: 2025/04/11 17:46:42 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Irc.hpp"

// Numeric Replies

#define ERR_NOSUCHNICK(nickname, channelname) (std::string(":401 ") + channelname + " " + nickname + " :No such nick/channel" + CRLF)
#define ERR_NOSUCHCHANNEL(channelname) (std::string(":403 ") + channelname + " :No such channel" + CRLF)
#define ERR_CANNOTSENDTOCHAN(channelname) (std::string(":404 ") + channelname + " :Cannot send to channel" + CRLF)
#define ERR_TOOMANYCHANNELS(channelname) (std::string(":405 ") + channelname + " :You have joined too many channels" + CRLF)
#define ERR_WASNOSUCHNICK(nickname) (std::string(":406 ") + nickname + " :There was no such nickname" + CRLF)
// 407 - ERR_TOOMANYTARGETS 

#define ERR_NOTEXTTOSEND() (std::string(":412 :No text to send") + CRLF)
#define ERR_NOTOPEVEL(mask) (std::string(":413 ") + mask + " :No toplevel domain specified" + CRLF)
#define ERR_WILDTOPLEVEL(mask) (std::string(":414 ") + mask + " :Wildcard in toplevel domain" + CRLF)
#define ERR_BADMASK(mask) (std::string(":415 ") + mask + " :Bad Server/host mask" + CRLF)

#define ERR_UNKNOWNCOMMAND(command) (std::string(":421 ") + command + " :Unknown command" + CRLF)
#define ERR_NOMOTD() (std::string(":422 :MOTD File is missing") + CRLF)
#define ERR_NONICKNAMEGIVEN() (std::string(":431 :No nickname given") + CRLF)
#define ERR_ERRONEUSNICKNAME(nickname) (std::string(":432 ") + nickname + " :Erroneous nickname" + CRLF)
#define ERR_NICKNAMEINUSE(nickname) (std::string(":433 ") + nickname + " :Nickname is already in use" + CRLF)
#define ERR_USERNOTINCHANNEL(nickname, channelname) (std::string(":441 ") + nickname + " " + channelname + " :They aren't on that channel" + CRLF)
#define ERR_NOTONCHANNEL(channelname) (std::string(":442 ") + channelname + " :You're not on that channel" + CRLF)
#define ERR_USERONCHANNEL(username, channelname) (std::string(":443 ") + username + " " + channelname + " :Is already on that channel" + CRLF)
#define ERR_USERSDISABLED() (std::string(":446 :USERS has been disabled") + CRLF)
#define ERR_NOTREGISTERED() (std::string(":451 :You have not registered") + CRLF)
#define ERR_NEEDMOREPARAMS(command) (std::string(":461 ") + command + " :Not enough parameters" + CRLF)
#define ERR_ALREADYREGISTERED() (std::string(":462 :Unauthorized command (already registered)") + CRLF)
#define ERR_PASSWDMISMATCH() (std::string(":464 :Password incorrect") + CRLF)
#define ERR_YOUREBANNEDCREEP() (std::string(":465 :You are banned from this server") + CRLF)
#define ERR_ERRORSYNTAXE(command) (command + std::string(" :Error syntaxe") + CRLF)

// Channel errors

#define ERR_KEYSET(channelname) (std::string(":467 ") + channelname + " :Channel key already set" + CRLF)
#define ERR_CHANNELISFULL(channelname) (std::string(":471 ") + channelname + " :Cannot join channel (+l)" + CRLF)
#define ERR_UNKNOWNMODE(modechar, channelname) (std::string(":472 ") + modechar + " :Is unknown mode char to me for " + channelname + CRLF)
#define ERR_INVITEONLYCHAN(channelname) (std::string(":473 ") + channelname + " :Cannot join channel (+i)" + CRLF)
#define ERR_BANNEDFROMCHAN(channelname) (std::string(":474 ") + channelname + " :Cannot join channel (+b)" + CRLF)
#define ERR_BADCHANNELKEY(channelname) (std::string(":475 ") + channelname + " :Cannot join channel (+k)" + CRLF)
#define ERR_BADCHANMASK(channelname) (std::string(":476 ") + channelname + " :Bad channel mask" + CRLF)
#define ERR_NOCHANMODES(channelname) (std::string(":477 ") + channelname + " :Channel doesn't support modes" + CRLF)
#define ERR_BANLISTFULL(channelname) (std::string(":478 ") + channelname + " :Channel ban list is full" + CRLF)
#define ERR_NOPRIVILEGES() (std::string(":481 :Permission Denied - You're not an IRC operator") + CRLF)
#define ERR_CHANOPRIVSNEEDED(channelname) (std::string(":482 ") + channelname + " :You're not channel operator" + CRLF)
#define ERR_UNIQOPRIVSNEEDED() (std::string(":485 :You're not the original channel operator") + CRLF)
#define ERR_UMODEUNKNOWNFLAG() (std::string(":501 :Unknown MODE flag") + CRLF)

//error personnalisee
#define ERR_USERONINVLIST(username, Channelname) (std::string(":Error ") + (username) + " " + (Channelname) + " :Already in invit list" + CRLF)
#define ERR_NEEDLESSPARAMS(command) (std::string(": ") + command + " :Too much params" + CRLF)
#define ERR_LASTCHANOP(channelname, nickname) (std::string(": ") + channelname + ":error " + nickname + " is the last operator of the channel" + CRLF)