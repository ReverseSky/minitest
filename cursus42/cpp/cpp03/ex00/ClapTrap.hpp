/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:46:57 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 13:50:25 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>


class ClapTrap
{

	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap();

		ClapTrap		&operator=(const ClapTrap &op);

		std::string		getname(void) const;
		unsigned int	gethit(void) const;
		unsigned int	getenergy(void) const;
		unsigned int	getattack(void) const;
		void			setname(std::string name);
		void			sethit(unsigned int hitpoint);
		void			setenergy(unsigned int energypoint);
		void			setattack(unsigned int attackdmg);

		void 			attack(const std::string &target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);

	private:

	std::string		name;
	unsigned int	hitpoint;
	unsigned int	energypoint;
	unsigned int	attackdmg;
};





#endif