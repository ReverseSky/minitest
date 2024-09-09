/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:17:32 by greg              #+#    #+#             */
/*   Updated: 2024/09/09 18:00:10 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog default constructor has been called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal::AAnimal(copy)
{
	std::cout << "Copy contructor has been called" << std::endl;
	this->brain = new Brain();
	*this = copy;
}

Dog::~Dog() 
{
	delete this->brain;
	std::cout << "Dog default destructor has been called" << std::endl;
}

Dog	&Dog::operator=(const Dog &op)
{
	this->AAnimal::operator=(op);
	*this->brain = *op.brain;

	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Dog : Ouaf !" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->brain);
}