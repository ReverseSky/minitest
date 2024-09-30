/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:03:19 by greg              #+#    #+#             */
/*   Updated: 2024/09/19 14:56:25 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("UNKNOWN")
{
	std::cout << "WrongAnimal default constructor has been called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal base constructor has been called for : " << this->type << "!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "Copy contructor has been called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor has been called for : " << this->type << "!" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &op)
{
	if (this != &op) 
		this->type = op.type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Unknow animal heard" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}