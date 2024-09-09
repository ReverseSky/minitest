/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:56:08 by greg              #+#    #+#             */
/*   Updated: 2024/09/09 16:10:38 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor has been called." << std::endl;
	size = 0;
}
Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor has been called." << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor has been called." << std::endl;
}

Brain	&Brain::operator=(const Brain &op)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = op.ideas[i];
	this->size = op.size;
	return (*this);
}
