/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:39:49 by greg              #+#    #+#             */
/*   Updated: 2024/09/11 18:30:43 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string name) : size(0), name(name)
{
	std::cout << "Character default constructor called for " << this->name << std::endl;
	int index = -1; while (++index < 4)
		this->inventory[index] = NULL;
}

Character::Character(const Character& copy)
{
	std::cout << "Character copy constructor called." << std::endl;
	*this = copy;
}

Character::~Character(void)
{
	std::cout << "Character default destructor called. " << this->name << " succesfully destroyed." << std::endl;
}


ICharacter::~ICharacter() 
{
	std::cout << "ICharacter interface default destructor called." << std::endl;
}

Character			&Character::operator=(const Character &op)
{
	if (this != &op) 
	{
		this->size = op.size;
		this->name = op.name;
		int	index = -1; 
		while (++index < 4)
			this->inventory[index] = op.inventory[index];
	}
	return *this;
}

std::string const &	Character::getName() const 
{
	return this->name;
}

void	Character::equip(AMateria *m) {
	if (this->size == 4) {
		std::cout << this->name << ": Inventory full ! Please unequip a Materia to equip : " << m->getType() << std::endl; return;
	}
	int	index = -1; while (++index < 4) 
	{
		if (this->inventory[index] == NULL) 
		{
			this->inventory[index] = m; std::cout << this->name << " succesfully equip AMateria " << m->getType() << " at index : " << index << "." << std::endl; 
			break;
		}
	}
	this->size++;
}


void	Character::unequip(int index) 
{
	if (this->size == 0) 
	{
		std::cout << this->name << "'s inventory is empty ! Equip an AMateria to unequip one." << std::endl; 
		return;
	}
	std::string type = this->inventory[index]->getType();
	this->inventory[index] = NULL; std::cout << this->name << " succesfully unequip AMateria " << type << " at index : " << index << "." << std::endl;
	this->size--;
}


void	Character::use(int index, ICharacter &target) 
{
	if (this->inventory[index] == NULL) {
		std::cout << "Nothing in slot " << index << " of " << this->name << "'s inventory." << std::endl; return;
	}
	if (this->inventory[index]->getType() == "ICE") {
		Ice *ice = dynamic_cast<Ice *>(this->inventory[index]); ice->use(target);
	}
	else if (this->inventory[index]->getType() == "CURE") {
		Cure *cure = dynamic_cast<Cure *>(this->inventory[index]); cure->use(target);
	}
}