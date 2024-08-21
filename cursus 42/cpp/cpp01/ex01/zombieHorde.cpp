/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:10:12 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/20 18:10:15 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
	int i = -1;

	Zombie *horde = new Zombie[n];
	while (++i < n)
	{
		horde[i].setname(name);
		horde[i].announce();
	}
	return horde;
}