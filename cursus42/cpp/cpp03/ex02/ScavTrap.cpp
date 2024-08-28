/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:08:51 by greg              #+#    #+#             */
/*   Updated: 2024/08/28 18:19:57 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
	this->setname(name);
	this->sethit(100);
	this->setenergy(50);
	this->setattack(20);
	std::cout << "ScavTrap " << name << " is created ! his stats are : " << std::endl;
	std::cout << "- Hit points : " << this->hitpoint << std::endl;
	std::cout << "- Energy points : " << this->energypoint << std::endl;
	std::cout << "- Attack damage : " << this->attackdmg << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.getname())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &op)
{
	this->setname(op.getname());
	this->sethit(op.gethit());
	this->setenergy(op.getenergy());
	this->setattack(op.getattack());
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " is destroyed" << std::endl;
}

void 	ScavTrap::attack(const std::string &target)
{
	if (this->hitpoint == 0)
		std::cout << "ScavTrap " << name << " tried to attack but it's not responding anymore !" << std::endl;
	else
	{
		if (energypoint > 0)
		{
			std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attackdmg << " points of damage !" << std::endl;
			this->energypoint -= 5;
		}
		else
			std::cout << "Scavtrap" << name << " had not enough energy to attack and did nothing !" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "Warning! ScavTrap " << name << " is now in gatekeeper mode!" << std::endl;
}