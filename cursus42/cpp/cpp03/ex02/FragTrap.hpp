/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:00:08 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/28 18:04:57 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	~FragTrap();

	FragTrap	&operator=(const FragTrap &op);

	void highFivesGuys(void);
	
	private:
	
};


#endif