/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 06:09:46 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 14:12:04 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DIAMONTRAP_H
#define DIAMONTRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{


	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &copy);
		~DiamondTrap();

		DiamondTrap	&operator=(DiamondTrap const &op);
		void whoAmI();

	private:
		std::string name;
};



#endif