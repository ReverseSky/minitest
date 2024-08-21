/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:27:12 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/17 22:30:39 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include "repertory.hpp"

class Contact
{

	public :

	Contact();
	~Contact();

	void	setfirst(std::string firstname);
	void	setlast(std::string lastname);
	void	setnick(std::string nickname);
	void	setphone(std::string phone);
	void	setsecret(std::string secret);

	std::string	getfirst() const;
	std::string	getlast() const;
	std::string	getnick() const;
	std::string	getphone() const;
	std::string	getsecret() const;

	private :

		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumb;
		std::string	secret;
};

#endif