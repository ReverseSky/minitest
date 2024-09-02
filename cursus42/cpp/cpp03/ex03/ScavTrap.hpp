/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:09:16 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 14:12:17 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap();

	ScavTrap	&operator=(const ScavTrap &op);

	void	guardGate();
	void	attack(const std::string &target);
	
private:
};
#endif