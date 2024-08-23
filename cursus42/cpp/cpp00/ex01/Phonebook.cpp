/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:07:50 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/23 10:53:27 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"

Phonebook::Phonebook() : current_contact(0), nb_contact(0)
{
}

Phonebook::~Phonebook(void)
{
}

void	Phonebook::add_contact()
{
	std::string	firstname;
	std::string lastname;
	std::string	nickname;
	std::string	phonenumb;
	std::string	secret;

	if (this->current_contact == 8)
		this->current_contact = 0;
	do
	{
	system("clear");
	std::cout << "type first name of the contact : " << std::endl;
	std::getline (std::cin, firstname);
	} while(firstname.empty() || firstname.find_first_not_of(" \t") == std::string::npos);
	do
	{
	system("clear");
	std::cout << "type last name of the contact : " << std::endl;
	std::getline (std::cin, lastname);
	} while(firstname.empty() || lastname.find_first_not_of(" \t") == std::string::npos);
	do
	{
	system("clear");
	std::cout << "type nickname of the contact : " << std::endl;
	std::getline (std::cin, nickname);
	} while(firstname.empty() || nickname.find_first_not_of(" \t") == std::string::npos);
	do
	{
	system("clear");
	std::cout << "type phone number of the contact : " << std::endl;
	std::getline (std::cin, phonenumb);
	} while(firstname.empty() || phonenumb.find_first_not_of(" \t") == std::string::npos || phonenumb.find_first_not_of("0123456789") != std::string::npos);
	do
	{
	system("clear");
	std::cout << "type secret of the contact : " << std::endl;
	std::getline (std::cin, secret);
	} while(firstname.empty() || secret.find_first_not_of(" \t") == std::string::npos);
	system("clear");
	this->array[this->current_contact].setfirst(firstname);
	this->array[this->current_contact].setlast(lastname);
	this->array[this->current_contact].setnick(nickname);
	this->array[this->current_contact].setphone(phonenumb);
	this->array[this->current_contact].setsecret(secret);
	this->current_contact ++;
	if (nb_contact < 8)
		nb_contact += 1;
}

void	Phonebook::search_contact()
{
	std::string	firstname;
	std::string lastname;
	std::string	nickname;
	std::string	phonenumb;
	std::string	secret;
	std::string prompt;
	int	index;
	int	i = 0;;

	system("clear");
	if (this->current_contact == 0)
	{
		std::cout << "Error phonebook is empty try to add one first" << std::endl;
		return;
	}
	std::cout << std::setw(5) << "Index" << "|";
	std::cout << std::setw(10) << "firstName" << "|";
	std::cout << std::setw(10) << "LastName" << "|";
	std::cout << std::setw(10) << "NickName" << std::endl;
	while (i < nb_contact)
	{
		firstname = this->array[i].getfirst();
		lastname = this->array[i].getlast();
		nickname = this->array[i].getnick();
		phonenumb = this->array[i].getphone();
		secret = this->array[i].getsecret();
		if (firstname.length() > 9)
			firstname = firstname.substr (0, 9) + ".";
		if (lastname.length() > 9)
			lastname = firstname.substr (0, 9) + ".";
		if (nickname.length() > 9)
			nickname = nickname.substr (0, 9) + ".";
		std::cout << std::setw(5) << i << "|";
		std::cout << std::setw(10) << firstname << "|";
		std::cout << std::setw(10) << lastname << "|";
		std::cout << std::setw(10) << nickname << std::endl;
		i++;
	}
	std::cout << "type contact index to have personnal informations" << std::endl;
	std::getline (std::cin, prompt);
	index = atoi(prompt.c_str());
	if ((index == 0 && prompt[0] != '0') || index > 7 || index < 0)
	{
		std::cout << "Error wrong index. Please enter a valid index" << std::endl;
		return ;
	}
	else if (index > this->nb_contact)
	{
		std::cout << "Error this contact doesn't exit" << std::endl;
		return ;
	}
	else
	{
		std::cout << "First name : " << this->array[index].getfirst() << std::endl;
		std::cout << "Last name : " << this->array[index].getlast() << std::endl;
		std::cout << "Nickname : " << this->array[index].getnick() << std::endl;
		std::cout << "Phone number : " << this->array[index].getphone() << std::endl;
		std::cout << "Secret : " << this->array[index].getsecret() << std::endl;
		std::cout << "Press a key to continue" << std::endl;
		getchar();
	}
}
