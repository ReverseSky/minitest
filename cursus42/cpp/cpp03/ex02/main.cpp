/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:47:13 by greg              #+#    #+#             */
/*   Updated: 2024/08/28 18:29:43 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	Jack("Jack");
	ScavTrap	Tina("Tina");
	FragTrap	Sereena("Sereena");	

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