#ifndef IRCPARSER_HPP
#define IRCPARSER_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Commands.hpp"

struct CommandHandler {
	std::string command;
	void (*handler)(const std::string &, const std::vector<std::string> &);
};

class IRCParser {
private:
	static const size_t commandCount = 8;
	CommandHandler commandTable[commandCount];

public:
	IRCParser();
	void handleMessage(const std::string &msg);

private:
	void executeCommand(const std::string &prefix, const std::string &command, const std::vector<std::string> &params);
};

#endif