/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:06:06 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/20 17:21:17 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
public:

	Zombie(std::string name);
	~Zombie();

	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);

private:

	std::string name;
	void	announce();
};

#endif