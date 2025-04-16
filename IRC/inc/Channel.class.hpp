/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:39:40 by momillio          #+#    #+#             */
/*   Updated: 2025/04/16 09:30:49 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Irc.hpp"

#define MAXMEMBER 10

class Client;

class Channel
{
private:
	std::string					_name;
	std::string					_topic;
	std::string					_topicSetBy;
	std::string					_key;
	size_t						_limit;

	std::set<std::string>	_banlist;
	std::set<std::string>		_invitelist;

	std::map<int, Client*>		_memberlist;
	std::set<int>				_operatorList;
	std::set<char>				_activeModes; // i, t, k, l

	bool						_inviteOnly;
	bool						_topicForOP;


public:
	Channel(std::string const &name);
	Channel(const std::string &name, const std::string &key);
	~Channel();

// getter
	std::string					getUsers() const;
	std::string const &			getName() const;
	std::string const &			getTopic() const;
	std::string const &			getKey() const;
	size_t						getLimit() const;
	bool						hasUser(std::string username);
	bool						hasKey() const;
	bool						hasLimit() const;
	bool						checkInvit(std::string username);
	bool						checkBan(const std::string username);
	bool						checkKey(const std::string& inputKey) const;
	bool						isOperator(int fd) const;
	bool const &				getInvOnly() const;
	bool const &				getTopicForOP() const;
	std::string					getModeString() const;
	size_t							getOperatorCount() const;
	size_t							getMemberListCount() const;

// setter
	void	setTopic(std::string const & topic);
	void	setKey(const std::string& key);
	void	unsetKey();
	void	setLimit(size_t limit);
	void	unsetLimit();

	void	setInvit(bool enable);			// +i / -i
	void	setTopicForOP(bool enable);		// +t / -t

// mode
	void	setMode(char mode);
	void	unsetMode(char mode);
	bool	hasMode(char mode) const;

// user
	void	addUser(Client *client, Server *server);
	void	removeUser(Client *client);
	void	kickUser(Client *client, Server *server);

	void	addOperator(int fd);
	void	removeOperator(int fd);

// invit ban
	void	addInvit(std::string username);
	void	removeInvit(std::string username);
	void	isBan(Client *client, Server* server);
	void	unban(std::string nickname);

// name
	static bool isNameValid(const std::string name);
};
