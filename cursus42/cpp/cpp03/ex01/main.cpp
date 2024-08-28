/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:47:13 by greg              #+#    #+#             */
/*   Updated: 2024/08/28 14:10:04 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Jack("Jack");
	ScavTrap	Tina("Tina");

	Tina.setattack(5);
	Jack.setattack(10);

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
	return (0);
}