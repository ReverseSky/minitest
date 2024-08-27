/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:04:20 by greg              #+#    #+#             */
/*   Updated: 2024/08/27 12:47:25 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0) 
{
}

Point::Point(float const x, float const y) : x(x), y(y) 
{
}

Point::Point(Point const &copy)
{
	*this = copy;
}
Point::~Point()
{
}


Point &Point::operator=(Point const&) 
{
	return (*this);
}

Fixed const	Point::getX(void) const
{
	return (this->x);
}

Fixed const	Point::getY(void) const
{
	return (this->y);
}

std::ostream	&operator<<(std::ostream &out, Point const &op) 
{
	out << "x:(" << op.getX() << "); y:(" << op.getY() << ");";
	return out;
}