/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:24:38 by greg              #+#    #+#             */
/*   Updated: 2024/09/04 04:52:18 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		AAnimal	&operator=(const AAnimal &op);
		std::string	getType() const;
		void	setType();

	protected:
		std::string type;

};


#endif