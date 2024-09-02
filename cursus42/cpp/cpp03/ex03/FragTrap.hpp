/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:00:08 by grobledo          #+#    #+#             */
/*   Updated: 2024/09/02 14:12:11 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	~FragTrap();

	FragTrap	&operator=(const FragTrap &op);

	void highFivesGuys(void);
	
	private:
	
};


#endif