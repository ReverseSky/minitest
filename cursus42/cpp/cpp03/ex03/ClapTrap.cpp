/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:47:18 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 13:02:14 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
{
	std::cout << "ClapTrap default constructor has been called !" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitpoint(10), energypoint(10), attackdmg(0)
{
	std::cout << "ClapTrap " << name << " is created ! his stats are : " << std::endl;
	std::cout << "- Hit points : " << hitpoint << std::endl;
	std::cout << "- Energy points : " << energypoint << std::endl;
	std::cout << "- Attack damage : " << attackdmg << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}


ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " is destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &op)
{
	this->setname(op.getname());
	this->sethit(op.gethit());
	this->setenergy(op.getenergy());
	this->setattack(op.getattack());
	return *this;
}

void	ClapTrap::setname(std::string name)
{
	this->name = name;
}

void	ClapTrap::sethit(unsigned int hitpoint)
{
	this->hitpoint = hitpoint;
}

void	ClapTrap::setenergy(unsigned int energypoint)
{
	this->energypoint = energypoint;
}

void	ClapTrap::setattack(unsigned int attackdmg)
{
	this->attackdmg = attackdmg;
}

std::string ClapTrap::getname() const
{
	return (this->name);
}

unsigned int ClapTrap::gethit() const
{
	return (this->hitpoint);
}

unsigned int ClapTrap::getenergy() const
{
	return (this->energypoint);
}

unsigned int ClapTrap::getattack() const
{
	return (this->attackdmg);
}

void 	ClapTrap::attack(const std::string &target)
{
	if (this->hitpoint == 0)
		std::cout << "ClapTrap " << name << " tried to attack but it's not responding anymore !" << std::endl;
	else
	{
		if (energypoint > 0)
		{
			std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackdmg << " points of damage !" << std::endl;
			this->energypoint -= 1;
		}
		else
			std::cout << "Claptrap" << name << " had not enough energy to attack and did nothing !" << std::endl;
	}
}
void 	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Claptrap " << name << " tooks " << amount << " points of damage !" << std::endl;
	if (this->hitpoint < amount)
		this->hitpoint = 0;
	else
		this->hitpoint -= amount;
	if (hitpoint < 1)
		std::cout << "ClapTrap " << name << "run out of hp !" << std::endl;
}

void 	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitpoint == 0)
		std::cout << "ClapTrap " << name << " tried to repair itself but it's not responding anymore !" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " repare itself and regen " << amount << " Hit points !" << std::endl;
		this->hitpoint += amount;
		this->energypoint -= 1;
	}
}
