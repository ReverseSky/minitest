/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:17:32 by greg              #+#    #+#             */
/*   Updated: 2024/09/04 04:53:57 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal::AAnimal("DOG")
{
	this->type = AAnimal::getType();
	std::cout << "Default Dog constructor has been called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal::AAnimal(copy)
{
	std::cout << "Copy contructor has been called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog destructor has been called" << std::endl;
	delete this->brain;
}

Dog	&Dog::operator=(const Dog &op)
{
	if (this != &op) 
		this->type = op.type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Dog : Ouaf !" << std::endl;
}