/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:08:25 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 18:45:14 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{

public:
	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog	&operator=(const Dog &op);
	void	makeSound(void) const;
	
	private:
	
};

#endif