/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:07:26 by grobledo          #+#    #+#             */
/*   Updated: 2025/04/10 21:06:59 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Irc.hpp"

/*431	ERR_NONICKNAMEGIVEN	Aucun pseudonyme fourni.
432	ERR_ERRONEUSNICKNAME	Pseudonyme invalide (caractères interdits, format incorrect, etc.).
433	ERR_NICKNAMEINUSE	Le pseudonyme est déjà utilisé.*/
// void Commands::handleNick(std::string prefix, std::vector<std::string> param, std::string trailing, Client * client, Server *srv)
// {
// 	(void)client;
// 	(void)srv;
// 	senderror(ERR_UMODEUNKNOWNFLAG() ,client->getFd());
// 	std::cout << "Prefix: " << prefix << std::endl;

// 	for (size_t i = 0; i < param.size(); ++i) {
// 		std::cout << ", param[" << i << "] = " << param[i] << std::endl;
// 	}
// 	std::cout << " trailing: " << trailing << std::endl;
// }


/*461	ERR_NEEDMOREPARAMS	Pas assez de paramètres fournis à la commande USER.
462	ERR_ALREADYREGISTRED	L'utilisateur est déjà enregistré (a déjà envoyé USER et NICK).*/
// void Commands::handleUser(std::string prefix, std::vector<std::string> param, std::string trailing, Client * client, Server *srv)
// {
// 	(void)client;
// 	(void)srv;
// 	std::cout << "Prefix: " << prefix << std::endl;

// 	for (size_t i = 0; i < param.size(); ++i) {
// 		std::cout << ", param[" << i << "] = " << param[i] << std::endl;
// 	}
// 	std::cout << " trailing: " << trailing << std::endl;
// }	


/*403	ERR_NOSUCHCHANNEL	Le canal spécifié n'existe pas.
405	ERR_TOOMANYCHANNELS	L'utilisateur a rejoint trop de canaux (limite atteinte).
471	ERR_CHANNELISFULL	Le canal est plein (limite d'utilisateurs atteinte).
473	ERR_INVITEONLYCHAN	Le canal est en mode +i (invitation uniquement).
474	ERR_BANNEDFROMCHAN	L'utilisateur est banni du canal.
475	ERR_BADCHANNELKEY	Mot de passe (clé) requis ou incorrect pour rejoindre le canal.*/
//join


/*411	ERR_NORECIPIENT	Aucun destinataire fourni pour le message.
412	ERR_NOTEXTTOSEND	Aucun texte de message fourni.
401	ERR_NOSUCHNICK	Le destinataire spécifié n’existe pas (nick ou canal).
404	ERR_CANNOTSENDTOCHAN	Impossible d’envoyer un message au canal (restreint, mode +n, etc.).
407	ERR_TOOMANYTARGETS	Trop de destinataires à la fois dans la commande.
413	ERR_NOTOPLEVEL	Nom de canal mal formé (rare, lié à des wildcards).
414	ERR_WILDTOPLEVEL	Wildcard invalide dans le nom du canal ou du destinataire.*/
void Commands::handlePrivmsg(std::string prefix, std::vector<std::string> param, std::string trailing, Client * client, Server *srv)
{
	(void)client;
	(void)srv;
	std::cout << "Prefix: " << prefix << std::endl;

	for (size_t i = 0; i < param.size(); ++i) {
		std::cout << ", param[" << i << "] = " << param[i] << std::endl;
	}
	std::cout << " trailing: " << trailing << std::endl;
}	


/*441	ERR_USERNOTINCHANNEL	L’utilisateur à expulser n’est pas présent dans le canal.
442	ERR_NOTONCHANNEL	Tu n’es pas sur le canal (et donc ne peux pas kick).
443	ERR_USERONCHANNEL	(Pas lié à KICK — concerne INVITE, à ignorer ici.)
461	ERR_NEEDMOREPARAMS	Paramètres manquants dans la commande KICK.
482	ERR_CHANOPRIVSNEEDED	Tu n’as pas les privilèges d’opérateur de canal.*/
// void Commands::handleKick(std::string prefix, std::vector<std::string> param, std::string trailing, Client * client, Server *srv)
// {
// 	(void)client;
// 	(void)srv;
// 	std::cout << "Prefix: " << prefix << std::endl;

// 	for (size_t i = 0; i < param.size(); ++i) {
// 		std::cout << ", param[" << i << "] = " << param[i] << std::endl;
// 	}
// 	std::cout << " trailing: " << trailing << std::endl;
// }	


/*401	ERR_NOSUCHNICK	Le pseudonyme spécifié n'existe pas.
442	ERR_NOTONCHANNEL	Tu n’es pas sur le canal.
443	ERR_USERONCHANNEL	L’utilisateur est déjà sur le canal.
461	ERR_NEEDMOREPARAMS	Paramètres manquants dans la commande.
482	ERR_CHANOPRIVSNEEDED	Tu n’es pas opérateur du canal.*/
// void Commands::handleInvite(std::string prefix, std::vector<std::string> param, std::string trailing, Client * client, Server *srv)
// {
// 	(void)client;
// 	(void)srv;
// 	std::cout << "Prefix: " << prefix << std::endl;

// 	for (size_t i = 0; i < param.size(); ++i) {
// 		std::cout << ", param[" << i << "] = " << param[i] << std::endl;
// 	}
// 	std::cout << " trailing: " << trailing << std::endl;
// }	


/*331	RPL_NOTOPIC	Le canal n’a pas de topic défini. (ce n’est pas une erreur bloquante)
332	RPL_TOPIC	Réponse normale contenant le topic. (pas une erreur)
403	ERR_NOSUCHCHANNEL	Le canal n'existe pas.
442	ERR_NOTONCHANNEL	Tu n’es pas dans le canal.
461	ERR_NEEDMOREPARAMS	Paramètres manquants dans la commande.
482	ERR_CHANOPRIVSNEEDED	Tu n’as pas les droits de modifier le topic (si canal en mode +t).*/
// void Commands::handleTopic(std::string prefix, std::vector<std::string> param, std::string trailing, Client * client, Server *srv)
// {
// 	(void)client;
// 	(void)srv;
// 	std::cout << "Prefix: " << prefix << std::endl;

// 	for (size_t i = 0; i < param.size(); ++i) {
// 		std::cout << ", param[" << i << "] = " << param[i] << std::endl;
// 	}
// 	std::cout << " trailing: " << trailing << std::endl;
// }	


/*403	ERR_NOSUCHCHANNEL	Le canal n'existe pas.
441	ERR_USERNOTINCHANNEL	L’utilisateur cible n’est pas dans le canal.
442	ERR_NOTONCHANNEL	Tu n’es pas dans le canal.
467	ERR_KEYSET	Une clé (mot de passe) est déjà définie pour le canal.
472	ERR_UNKNOWNMODE	Le mode spécifié est inconnu ou invalide.
474	ERR_BANNEDFROMCHAN	Tu es banni du canal. (pareil, utile si tu t’auto-modifies)
476	ERR_BADCHANMASK	Masque de canal invalide. (rare)
477	ERR_NOCHANMODES	Impossible de définir des modes sur ce type de canal.
478	ERR_BANLISTFULL	La liste des bans est pleine (ex : +b).
482	ERR_CHANOPRIVSNEEDED	Tu n’as pas les droits nécessaires pour modifier les modes.
502	ERR_USERSDONTMATCH	Tu essaies de changer les modes d’un autre utilisateur.*/
// void Commands::handleMode(std::string prefix, std::vector<std::string> param, std::string trailing, Client * client, Server *srv)
// {
// 	(void)client;
// 	(void)srv;
// 	std::cout << "Prefix: " << prefix << std::endl;

// 	for (size_t i = 0; i < param.size(); ++i) {
// 		std::cout << ", param[" << i << "] = " << param[i] << std::endl;
// 	}
// 	std::cout << " trailing: " << trailing << std::endl;
// }	

// void Commands::handlePass(std::string prefix, std::vector<std::string> param, std::string trailing, Client * client, Server *srv)
// {
// 	(void)client;
// 	(void)srv;
// 	std::cout << "Prefix: " << prefix << std::endl;

// 	for (size_t i = 0; i < param.size(); ++i) {
// 		std::cout << ", param[" << i << "] = " << param[i] << std::endl;
// 	}
// 	std::cout << " trailing: " << trailing << std::endl;
// }	