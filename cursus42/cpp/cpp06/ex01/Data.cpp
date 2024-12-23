/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:08:27 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 17:17:36 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _size(10)
{
	std::cout << "Data default constructor called" << std::endl;
}
Data::Data(const Data &copy)
{
	*this = copy;
}
Data::~Data()
{
	std::cout << "Data default destructor called" << std::endl;
}

Data	&Data::operator=(const Data &op)
{
	if (this != &op)
		this->_size = op._size;
	return *this;
}

std::ostream	&operator<<(std::ostream & out, Data const &op)
{
	out << op.getSize();
	return out;
}

int	Data::getSize() const
{
	return this->_size;
}
