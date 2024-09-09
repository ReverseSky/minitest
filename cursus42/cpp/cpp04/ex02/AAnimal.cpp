/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:54:45 by greg              #+#    #+#             */
/*   Updated: 2024/09/04 04:52:36 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("UNKNOWN")
{
	std::cout << "AAnimal default constructor has been called" << std::endl;
}
AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal base constructor has been called for : " << this->type << "!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "Copy contructor has been called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal default destructor has been called for : " << this->type << "!" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &op)
{
	if (this != &op) 
		this->type = op.type;
	return *this;
}

void	AAnimal::makeSound() const
{
	std::cout << "Unknow Aanimal sound heard !" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}

void	AAnimal::setType()
{
	this->type = type;
}