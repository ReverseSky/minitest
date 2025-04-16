/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:40:41 by momillio          #+#    #+#             */
/*   Updated: 2025/04/16 09:51:45 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

Channel::Channel(const std::string &name) : _name(name), _limit(0), _inviteOnly(false), _topicForOP(false) {}

Channel::Channel(const std::string &name, const std::string &key) : _name(name), _key(key), _limit(10), _inviteOnly(false), _topicForOP(false) 
{
	char prefix = name[0];

	if (prefix == '#') {
		// Modes par défaut pour les channels normaux : +nt
		setMode('n'); // si tu le gères
		setMode('t');
	}
	setMode('k');
}
Channel::~Channel()
{
}
//getter

std::string Channel::getUsers() const {
	std::string users;

	for (std::map<int, Client*>::const_iterator it = _memberlist.begin(); it != _memberlist.end(); ++it) {
		if (!users.empty())
			users += " ";

		if (isOperator(it->first))
			users += "@";

		users += it->second->getNickname();
	}

	return users;
}

std::string const &	Channel::getName() const {
	return this->_name;
}

std::string const & Channel::getTopic() const {
	return this->_topic;
}

const std::string& Channel::getKey() const {
	return _key;
}

size_t Channel::getLimit() const {
	return _limit;
}

bool Channel::hasUser(std::string Nickname) {
	for (std::map<int, Client*>::iterator it = _memberlist.begin(); it != _memberlist.end(); ++it) {
		if (it->second->getNickname() == Nickname)
			return true;
	}
	return false;
}

bool Channel::hasKey() const {
	return hasMode('k');
}

bool Channel::hasLimit() const {
	return hasMode('l');
}

bool Channel::checkInvit(std::string nickname) {
	if (_invitelist.find(nickname) != _invitelist.end())
			return true;
	else
		return false;
}

bool Channel::checkBan(const std::string Nickname) {
	if (_banlist.find(Nickname) != _banlist.end())
		return true;
	else
		return false;
}

bool Channel::checkKey(const std::string& inputKey) const {
	if (_key.empty())
		return true;
	return _key == inputKey;
}

bool Channel::isOperator(int fd) const {
	return _operatorList.find(fd) != _operatorList.end();
}

const bool & Channel::getInvOnly() const {
	return _inviteOnly;
}

const bool & Channel::getTopicForOP() const {
	return _topicForOP;
}

std::string Channel::getModeString() const {
	std::string result = "+";
	if (hasMode('i')) result += "i";
	if (hasMode('t')) result += "t";
	if (hasMode('k')) result += "k";
	if (hasMode('l')) result += "l";
	if (hasMode('b')) result += "b";
	return result;
}

size_t	Channel::getOperatorCount() const {
	return (_operatorList.size());
}

size_t	Channel::getMemberListCount() const {
	return (_memberlist.size());
}

// setter

void Channel::setTopic(const std::string &topic) {
	this->_topic = topic;
}

void Channel::setKey(const std::string& key) {
	this->_key = key;
	setMode('k');
}

void Channel::unsetKey() {
	this->_key.clear();
	unsetMode('k');
}

void Channel::setLimit(size_t limit) {
	this->_limit = limit;
	setMode('l');
}

void Channel::unsetLimit() {
	this->_limit = 0;
	unsetMode('l');
}

void Channel::setInvit(bool invitOnly) {
	this->_inviteOnly = invitOnly;
	if (invitOnly)
		setMode('i');
	else
		unsetMode('i');
}

void Channel::setTopicForOP(bool topic) {
	this->_topicForOP = topic;
	// topic ? setMode('t') : unsetMode('t');
}

// mode gestion

void Channel::setMode(char mode) {
	_activeModes.insert(mode);
}

void Channel::unsetMode(char mode) {
	_activeModes.erase(mode);
}

bool Channel::hasMode(char mode) const {
	return _activeModes.find(mode) != _activeModes.end();
}

// user

void Channel::addUser(Client * client, Server *server) {
	if (_memberlist.size() >= MAXMEMBER) {
		server->reply(ERR_CHANNELISFULL(_name), client);
		return;
	}
	if (hasUser(client->getNickname()))
		return;
	_memberlist[client->getFd()] = client;

	if (_memberlist.size() == 1)
		addOperator(client->getFd()); // premier arrivé = opérateur
}

void Channel::removeUser(Client* client) {
	int fd = client->getFd();
	_memberlist.erase(fd);
	_operatorList.erase(fd);
	client->removeChannel(this->getName());
}

void Channel::kickUser(Client *client, Server *server) {
	int fd = client->getFd();
	if (_memberlist.find(fd) != _memberlist.end())
		_memberlist.erase(fd);
	else
		server->reply(ERR_USERNOTINCHANNEL(client->getNickname(), _name), client);
}

// operators
void Channel::addOperator(int fd) {
	_operatorList.insert(fd);
}

void Channel::removeOperator(int fd) {
	_operatorList.erase(fd);
}


// invit ban channel
void Channel::addInvit(std::string nickname) {
	_invitelist.insert(nickname);
}

void	Channel::removeInvit(std::string nickname)
{
	_invitelist.erase(nickname);
}

void Channel::isBan(Client *client, Server *server) {
	if (_banlist.size() >= MAXMEMBER) {
		server->reply(ERR_BANLISTFULL(_name), client);
		return;
	}
	if (checkBan(client->getNickname()))
		return;
	_banlist.insert(client->getNickname());
}

void	Channel::unban(std::string nickname)
{
	_banlist.erase(nickname);
}

// check name
bool Channel::isNameValid(const std::string name) {
	if (name.length() > 50)
		return false;
	if (name.find_first_of("#", 0) != 0)
		return false;
	if (name.find_first_of(" ,") != std::string::npos)
		return false;
	return true;
}
