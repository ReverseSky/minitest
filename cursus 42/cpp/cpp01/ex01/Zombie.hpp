/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:06:06 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/20 18:04:00 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
public:

	Zombie();
	~Zombie();
	void	announce() const;
	void	setname(std::string name);
private:

	std::string name;
};

	Zombie* zombieHorde( int N, std::string name );

#endif