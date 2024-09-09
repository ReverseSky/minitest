/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:49:55 by greg              #+#    #+#             */
/*   Updated: 2024/09/05 18:30:46 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria::AMateria("CURE")
{
	std::cout << "Cure default constructor has been called" << std::endl;
	this->type = AMateria::type;
}

Cure::Cure(const Cure &copy) : AMateria::AMateria(copy)
{
	*this = copy;
}

Cure::~Cure()
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure	&Cure::operator=(const Cure &op)
{
	if (this != &op)
		this->type = op.type;
	return (*this);
}

AMateria	*Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s Wounds *" << std::endl;
}