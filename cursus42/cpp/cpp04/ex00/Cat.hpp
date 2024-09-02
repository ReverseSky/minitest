/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:03:35 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 18:45:23 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{

public:
	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat	&operator=(const Cat &op);
	void	makeSound(void) const;
	
	private:
	
};

#endif