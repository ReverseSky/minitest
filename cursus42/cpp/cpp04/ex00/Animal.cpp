/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:54:45 by greg              #+#    #+#             */
/*   Updated: 2024/09/19 14:54:46 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("UNKNOWN")
{
	std::cout << "Animal default constructor has been called" << std::endl;
}
Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal base constructor has been called for : " << this->type << "!" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Copy contructor has been called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor has been called for : " << this->type << "!" << std::endl;
}

Animal	&Animal::operator=(const Animal &op)
{
	if (this != &op) 
		this->type = op.type;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "Unknow animal sound heard !" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}