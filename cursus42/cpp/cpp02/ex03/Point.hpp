/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:02:49 by greg              #+#    #+#             */
/*   Updated: 2024/08/27 12:47:31 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{

public:
	Point();
	Point(float const x, float const y);
	Point(Point const &copy);
	~Point();

	Point &operator=(Point const &op);

	Fixed const	getX(void) const;
	Fixed const getY(void) const;

private:

	Fixed const	x;
	Fixed const	y;

};

std::ostream	&operator<<(std::ostream &out, Point const &op);

#endif