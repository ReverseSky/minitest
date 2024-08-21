/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:05 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/21 16:08:28 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	public :

	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon &weapon);
	void	attack() const;


	private :
	
		std::string	name;
		Weapon	*weapon;
};

#endif