/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:25:28 by greg              #+#    #+#             */
/*   Updated: 2024/09/19 13:48:55 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main() {
	IMateriaSource	*src = new MateriaSource();
	AMateria		*tmp;
	ICharacter		*bob = new Character("Bob");

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("ice");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("ice");
	bob->equip(tmp);

	bob->use(0, *bob);
	bob->use(1, *bob);
	bob->use(2, *bob);
	bob->use(3, *bob);

	bob->unequip(1);
	
	bob->use(0, *bob);
	bob->use(1, *bob);
	bob->use(2, *bob);

	src->getmaterias();

	delete src;
	delete bob;
	return 0;
}


// int main()
// {
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// ICharacter* me = new Character("me");
// AMateria* tmp;
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);
// delete bob;
// delete me;
// delete src;
// return 0;
// }