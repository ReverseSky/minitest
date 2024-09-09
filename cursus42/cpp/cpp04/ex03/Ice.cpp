/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:45:22 by greg              #+#    #+#             */
/*   Updated: 2024/09/05 18:30:53 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria::AMateria("ICE")
{
	std::cout << "Ice default constructor has been called" << std::endl;
	this->type = AMateria::type;
}

Ice::Ice(const Ice &copy) :AMateria::AMateria(copy)
{
	*this = copy;
}

Ice::~Ice()
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice	&Ice::operator=(const Ice &op)
{
	if (this != &op)
		this->type = op.type;
	return (*this);
}

AMateria	*Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* Shoots an ice bolt at " << target.getName() << " *" << std::endl;
}