#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <vector>

void handleNick(const std::string &, const std::vector<std::string> &);
void handleUser(const std::string &, const std::vector<std::string> &);
void handleJoin(const std::string &, const std::vector<std::string> &);
void handlePrivmsg(const std::string &, const std::vector<std::string> &);
void handleKick(const std::string &, const std::vector<std::string> &);
void handleInvite(const std::string &, const std::vector<std::string> &);
void handleTopic(const std::string &, const std::vector<std::string> &);
void handleMode(const std::string &, const std::vector<std::string> &); // <- nouveau

#endif
