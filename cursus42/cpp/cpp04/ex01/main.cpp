/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:54:38 by greg              #+#    #+#             */
/*   Updated: 2024/09/09 16:21:02 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


#define N_ANIMALS 10

int	main() 
{

	Dog *dog = new Dog();
	Cat *cat = new Cat();
	std::cout << std::endl;

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	
	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;



	// TEST DEEP COPY
	std::cout << "deep copy test" << std::endl << std::endl;

	cat->getBrain()->ideas[0] = "I like potatoes";
	cat->getBrain()->ideas[1] = "I like ice cream";

	std::cout << "Cat ideas:" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Create cat2" << std::endl;
	Cat *cat2 = new Cat();
	std::cout << std::endl;

	std::cout << "Cat2 ideas" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat2->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat2 = Cat" << std::endl;
	*cat2 = *cat;
	std::cout << std::endl;

	std::cout << "Cat ideas:" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat2 ideas" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat2->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat ideas (now he hates ice cream)" << std::endl;
	cat->getBrain()->ideas[1] = "I hate ice cream";
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat2 ideas" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat2->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	delete dog;
	delete cat;
	delete cat2;
	std::cout << std::endl;

	std::cout << "Subject test" << std::endl;

	Animal *animals[N_ANIMALS];

	for (int i = 0; i < N_ANIMALS; i++) {
		if (i < N_ANIMALS / 2) {
			animals[i] = new Cat();
		} else {
			animals[i] = new Dog();
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < N_ANIMALS; i++) {
		animals[i]->makeSound();
	}

	std::cout << std::endl;

	for (int i = 0; i < N_ANIMALS; i++) {
		delete animals[i];
	}
}

