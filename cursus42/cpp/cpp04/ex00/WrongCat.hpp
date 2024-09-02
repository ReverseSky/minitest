/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:07:12 by greg              #+#    #+#             */
/*   Updated: 2024/09/02 18:14:14 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	~WrongCat();

	WrongCat	&operator=(const WrongCat &op);
	void	makeSound(void) const;
	
	private:
	
};

#endif