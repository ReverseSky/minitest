/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:08:09 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 18:13:32 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal::WrongAnimal("WRONGCAT")
{

	std::cout << "WrongCat default constructor has been called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal::WrongAnimal(copy)
{
	std::cout << "Copy contructor has been called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() 
{
	std::cout << "WrongCat default destructor has been called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &op)
{
	if (this != &op) 
		this->type = op.type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat : Meow !" << std::endl;
}