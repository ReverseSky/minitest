/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:54:38 by greg              #+#    #+#             */
/*   Updated: 2024/09/19 15:01:49 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

// int main()
// {
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// meta->makeSound();

// delete i;
// delete j;
// delete meta;

// return 0;
// }


int	main() {
	WrongAnimal	*unknown = new WrongAnimal();
	Dog		*dog = new Dog();


	std::cout << unknown->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;

	unknown->makeSound();
	dog->makeSound();
	delete unknown;
	std::cout << std::endl;
	WrongAnimal *wrongcat = new WrongCat();
	wrongcat->makeSound();
	delete dog;
	delete wrongcat;
}