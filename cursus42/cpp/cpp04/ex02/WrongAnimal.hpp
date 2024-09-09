/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:02:22 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 18:06:27 by greg             ###   ########.fr       */
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
		void	setType();

	protected:
		std::string type;

};


#endif