/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:07:50 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/17 22:35:59 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::setfirst(std::string firstname)
{
	this->firstname = firstname;
}
void	Contact::setlast(std::string lastname)
{
	this->lastname = lastname;
}

void	Contact::setnick(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::setphone(std::string phonenumb)
{
	this->phonenumb = phonenumb;
}

void	Contact::setsecret(std::string secret)
{
	this->secret = secret;
}
std::string	Contact::getfirst() const
{
	return this->firstname;
}

std::string	Contact::getlast() const
{
	return this->lastname;
}

std::string	Contact::getnick() const
{
	return this->nickname;
}

std::string	Contact::getphone() const
{
	return this->phonenumb;
}

std::string	Contact::getsecret() const
{
	return this->secret;
}