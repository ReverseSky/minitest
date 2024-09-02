/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 06:09:43 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 12:58:57 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(void) 
{
	std::cout << "DiamondTrap default constructor called." << std::endl;
	this->name = ClapTrap::name;
	this->hitpoint = FragTrap::hitpoint;
	this->energypoint = ScavTrap::energypoint;
	this->attackdmg = FragTrap::attackdmg;

}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap()
{
	this->name = ClapTrap::name;
	this->hitpoint = FragTrap::hitpoint;
	this->energypoint = ScavTrap::energypoint;
	this->attackdmg = FragTrap::attackdmg;
	std::cout << "DiamondTrap " << name << "_clap_name is created ! his stats are : " << std::endl;
	std::cout << "- Hit points : " << FragTrap::hitpoint << std::endl;
	std::cout << "- Energy points : " << ScavTrap::energypoint << std::endl;
	std::cout << "- Attack damage : " << FragTrap::attackdmg << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is destroyed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &op)
{
	if (this != &op)
	{
		this->name = op.name;
		this->hitpoint = op.hitpoint;
		this->energypoint = op.energypoint;
		this->attackdmg = op.attackdmg;
	}
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I'm " << this->name << ", and my ClapTrap's name is " << ClapTrap::name << "." << std::endl;
}