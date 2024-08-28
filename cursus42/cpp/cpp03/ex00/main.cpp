/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:47:13 by greg              #+#    #+#             */
/*   Updated: 2024/08/27 17:08:03 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Jack("Jack");
	ClapTrap	Tina("Tina");

	Tina.setattack(3);
	Jack.setattack(1);

	Tina.attack("jack");
	std::cout << "Claptrap Tina have " << Tina.getenergy() << " energy point left !" << std::endl;
	Jack.takeDamage(Tina.getattack());
	Jack.beRepaired(3);
	std::cout << "Claptrap Jack should have " << Jack.getenergy() << " energy point left but lost everything due to a malfunction !" << std::endl;
	Jack.setenergy(0);
	Jack.beRepaired(2);
	Jack.attack("Tina");
	Tina.setattack(10);
	std::cout << "ClapTrap Tina charge her ultimate attack !" << std::endl;
	Tina.attack("Jack");
	Jack.takeDamage(Tina.getattack());
	Jack.attack("Tina");
	Jack.beRepaired(1);
	return (0);
}