#include "Commands.hpp"
#include <iostream>

void handleMode(const std::string &prefix, const std::vector<std::string> &params) {
	if (params.size() < 2) {
		std::cout << "[MODE] Erreur: pas assez de paramètres" << std::endl;
		return;
	}

	std::string target = params[0];     // Ex: #channel
	std::string modeStr = params[1];    // Ex: -k
	std::string argument = params.size() >= 3 ? params[2] : "";

	std::cout << "[MODE] " << prefix << " veut appliquer " << modeStr
	          << " sur " << target;

	if (!argument.empty())
		std::cout << " avec argument : " << argument;

	std::cout << std::endl;
}