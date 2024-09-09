/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:02:02 by greg              #+#    #+#             */
/*   Updated: 2024/09/09 18:00:34 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default constructor has been called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal::Animal(copy)
{
	std::cout << "Copy contructor has been called" << std::endl;
	this->brain = new Brain();
	*this = copy;
}

Cat::~Cat() 
{
	delete this->brain;
	std::cout << "Cat default destructor has been called" << std::endl;
}

Cat	&Cat::operator=(const Cat &op)
{
	this->Animal::operator=(op);
	*this->brain = *op.brain;

	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Cat : Meow !" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->brain);
}