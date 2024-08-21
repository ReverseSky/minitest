/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:12:13 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/21 16:16:03 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}
Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string ntype)
{
	this->type = ntype;
}

const std::string &Weapon::gettype() const
{
	return this->type;
}