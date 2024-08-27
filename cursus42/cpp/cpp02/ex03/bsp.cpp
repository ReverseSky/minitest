/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:22:26 by greg              #+#    #+#             */
/*   Updated: 2024/08/27 12:50:30 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float area(const Point& a, const Point& b, const Point& c)
{
	float x1, y1;
	float x2, y2;
	float x3, y3;

	x1 = a.getX().toFloat();
	y1 = a.getY().toFloat();
	x2 = b.getX().toFloat();
	y2 = b.getY().toFloat();
	x3 = c.getX().toFloat();
	y3 = c.getY().toFloat();

	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool	bsp(const Point& a, const Point& b, const Point& c, const Point& point)
{
	/* Calculate area of triangle ABC */
	float A = area(a, b, c);

	/* Calculate area of triangle PBC */
	float A1 = area(point, b, c);

	/* Calculate area of triangle APC */
	float A2 = area(a, point, c);

	/* Calculate area of triangle ABP */
	float A3 = area(a, b, point);

	if (A == A1 + A2 + A3)
		return true;
	return false;
}