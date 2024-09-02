/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:02:02 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 18:48:52 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include "Animal.hpp"

Cat::Cat() : Animal::Animal("CAT")
{
	this->type = Animal::getType();
	std::cout << "Cat default constructor has been called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal::Animal(copy)
{
	std::cout << "Copy contructor has been called" << std::endl;
	*this = copy;
}

Cat::~Cat() 
{
	std::cout << "Cat default destructor has been called" << std::endl;
}

Cat	&Cat::operator=(const Cat &op)
{
	if (this != &op) 
		this->type = op.type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Cat : Meow !" << std::endl;
}