/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:00:14 by grobledo          #+#    #+#             */
/*   Updated: 2024/09/02 13:01:34 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called." << std::endl;
	this->setattack(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap()
{
	this->setname(name);
	this->sethit(100);
	this->setenergy(100);
	this->setattack(30);
	std::cout << "FragTrap " << name << "is created ! his stats are : " << std::endl;
	std::cout << "- Hit points : " << this->hitpoint << std::endl;
	std::cout << "- Energy points : " << this->energypoint << std::endl;
	std::cout << "- Attack damage : " << this->attackdmg << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap	&FragTrap::operator=(const FragTrap &op)
{
	this->setname(op.getname());
	this->sethit(op.gethit());
	this->setenergy(op.getenergy());
	this->setattack(op.getattack());
	return *this;
}


FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " is destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " request everyone to do a high five !" << std::endl;
}
