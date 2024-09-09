/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:54:38 by greg              #+#    #+#             */
/*   Updated: 2024/09/04 04:42:18 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main() 
{
	const Animal* j = new Dog();
	const Animal* k = new Cat();
	delete j;
	delete k;

	Animal	*array[100];
	int		i = 0;

	while (i < 50)
		array[i++] = new Dog();
	while (i < 100)
		array[i++] = new Cat();

	array[4]->makeSound();
	array[72]->makeSound();
	for (i = 0; i < 100; i++)
	delete array[i];
	

	return 0;
}

