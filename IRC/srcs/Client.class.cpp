/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:38:25 by momillio          #+#    #+#             */
/*   Updated: 2025/04/16 09:41:48 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

Client::Client(Server *srv) 
: _fd(-1), _isAuthentified(false), _hasEnteredPass(false),
	_welcomeSent(false), _srv(srv)
{
}

Client::~Client()
{
}

// setter

void	Client::setFd(int fd)
{
	this->_fd = fd;
}

void	Client::setNickname(std::string const & nick)
{
	this->_nickname = nick;
}

void	Client::setUsername(std::string const & user)
{
	this->_username = user;
}

void		Client::setRealname(std::string const & realName)
{
	this->_realname = realName;
}

void	Client::setIpAdd(std::string ipAdd)
{
	this->_ipAdd = ipAdd;	
}

void	Client::setHasEnteredPass()
{
	this->_hasEnteredPass = true;
}

void	Client::setIsAuthentified()
{
	this->_isAuthentified = true;
	_srv->sendRegistrationMsg(this);
}

bool	Client::HasRequiredInfos()
{
	if (getNickname().empty() || getUsername().empty() || !getHasEnteredPass())
		return false;
	return true;
}

void	Client::setWelcomeSent()
{
	this->_welcomeSent = true;
}
// getter

int	Client::getFd() const
{
	return this->_fd;
}

std::string const &	Client::getNickname() const
{
	return this->_nickname;
}

std::string const &	Client::getUsername() const
{
	return this->_username;
}

std::string const &	Client::getRealname() const
{
	return this->_realname;
}

std::string const &	Client::getIpAdd() const
{
	return this->_ipAdd;
}

std::string & Client::getReplyBuffer()
{
	return this->_replybuffer;
}

bool	Client::getIsAuthentified() const
{
	return this->_isAuthentified;	
}

bool	Client::getHasEnteredPass() const
{
	return this->_hasEnteredPass;
}


bool	Client::getWelcomeSent() const
{
	return this->_welcomeSent;
}

std::string const Client::getPrefix() const 
{
	return _nickname + "!" + _username + "@" + _ipAdd;
}

void			Client::joinChannel(Channel * channel, Server *server)
{
	if (_channelList.size() >= 10){
		server->reply(ERR_TOOMANYCHANNELS(channel->getName()), this);
		return;
	}
	_channelList[channel->getName()] = channel;
}


// chhanel gestion

void Client::leaveAllChannels(Server *server) {
	std::vector<std::string> channelNames;
	for (std::map<std::string, Channel*>::const_iterator it = _channelList.begin(); it != _channelList.end(); ++it)
		channelNames.push_back(it->first);

	for (size_t i = 0; i < channelNames.size(); ++i) {
		Channel *chan = _channelList[channelNames[i]];
		if (chan){
			chan->removeUser(this);
			if (chan->getMemberListCount() == 0)
				server->removeChannel(chan->getName());
		}
	}
	server->removeinvban(_nickname);
	_channelList.clear(); // au cas où removeUser ne le fait pas
}

void	Client::removeChannel(const std::string& channelName)
{
	_channelList.erase(channelName);
}

