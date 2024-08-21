/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:11:49 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/21 16:16:02 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	
	void	setType(std::string ntype);
	const std::string	&gettype() const;

private:

	std::string type;
};


#endif