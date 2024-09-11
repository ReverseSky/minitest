/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:40:45 by greg              #+#    #+#             */
/*   Updated: 2024/09/11 18:37:30 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("UNKNOWN")
{
	std::cout << "AMateria default constructor has been called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria base constructor has been called for type : " << this->type << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria::~AMateria()
{
	std::cout << "AMateria default destructor has been called" << std::endl;
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}

AMateria &	AMateria::operator=(AMateria const &op) 
{
	if (this != &op)
		this->type = op.type;
	return *this;
}

void	AMateria::use(int, ICharacter &	) {}