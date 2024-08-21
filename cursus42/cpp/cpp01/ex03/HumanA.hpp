/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:12:42 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/21 16:05:35 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
	public :

	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void	attack() const;


	private :
		std::string	name;
		Weapon	&weapon;
};

#endif