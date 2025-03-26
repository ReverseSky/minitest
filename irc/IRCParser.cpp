#include "IRCParser.hpp"

// Constructeur avec 8 commandes
IRCParser::IRCParser() {
	commandTable[0] = {"NICK", handleNick};
	commandTable[1] = {"USER", handleUser};
	commandTable[2] = {"JOIN", handleJoin};
	commandTable[3] = {"PRIVMSG", handlePrivmsg};
	commandTable[4] = {"KICK", handleKick};
	commandTable[5] = {"INVITE", handleInvite};
	commandTable[6] = {"TOPIC", handleTopic};
	commandTable[7] = {"MODE", handleMode};
}

void IRCParser::handleMessage(const std::string &msg) {
	std::string prefix, command;
	std::vector<std::string> params;
	std::istringstream stream(msg);
	std::string word;

	if (!msg.empty() && msg[0] == ':') {
		stream >> prefix;
		prefix = prefix.substr(1);
	}

	if (!(stream >> command))
		return;

	while (stream >> word) {
		if (word[0] == ':') {
			std::string rest;
			std::getline(stream, rest);
			params.push_back(word.substr(1) + rest);
			break;
		}
		params.push_back(word);
	}

	executeCommand(prefix, command, params);
}

void IRCParser::executeCommand(const std::string &prefix, const std::string &command, const std::vector<std::string> &params) {
	for (size_t i = 0; i < commandCount; ++i) {
		if (commandTable[i].command == command) {
			commandTable[i].handler(prefix, params);
			return;
		}
	}
	std::cout << "Commande inconnue : " << command << std::endl;
}