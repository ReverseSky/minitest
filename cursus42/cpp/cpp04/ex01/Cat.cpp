/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:02:02 by greg              #+#    #+#             */
/*   Updated: 2024/09/04 02:02:45 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal::Animal("CAT")
{
	this->type = Animal::getType();
	std::cout << "Cat default constructor has been called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal::Animal(copy)
{
	std::cout << "Copy contructor has been called" << std::endl;
	*this = copy;
}

Cat::~Cat() 
{
	delete this->brain;
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