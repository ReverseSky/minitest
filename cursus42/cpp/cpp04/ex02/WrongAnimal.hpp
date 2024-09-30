/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:02:22 by greg              #+#    #+#             */
/*   Updated: 2024/09/19 14:43:23 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		~WrongAnimal();

		void	makeSound() const;
		WrongAnimal	&operator=(const WrongAnimal &op);
		std::string	getType() const;
	protected:
		std::string type;

};


#endif