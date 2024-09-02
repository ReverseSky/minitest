/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:47:13 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 13:00:15 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	Jack("Jack");
	std::cout << std::endl;
	ScavTrap	Tina("Tina");
	std::cout << std::endl;
	FragTrap	Sereena("Sereena");
	std::cout << std::endl;
	DiamondTrap Moxxxi("Moxxi");
	std::cout << std::endl;

	Moxxxi.attack("Sereena");
	Sereena.takeDamage(Moxxxi.getattack());
	Tina.setattack(5);
	Jack.setattack(10);
	Sereena.attack("Tina");
	Tina.takeDamage(Sereena.getattack());
	Tina.attack("jack");
	std::cout << "Claptrap tina have " << Tina.getenergy() << " energy point left !" << std::endl;
	Jack.takeDamage(Tina.getattack());
	Jack.beRepaired(3);
	Jack.setenergy(0);
	Jack.beRepaired(2);
	Jack.attack("Tina");
	Tina.setattack(10);
	Tina.attack("Jack");
	Jack.takeDamage(Tina.getattack());
	Jack.attack("Tina");
	Jack.beRepaired(1);
	Tina.guardGate();
	Sereena.highFivesGuys();
	return (0);
}