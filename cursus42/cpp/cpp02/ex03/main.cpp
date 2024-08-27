/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:11:07 by greg              #+#    #+#             */
/*   Updated: 2024/08/27 12:54:53 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);

static void	printData(const Point& A, const Point& B, const Point& C, const Point& P)
{
	std::cout << "Triangle vertices are ";
	std::cout << "A(" << A.getX().toFloat() << ", " << A.getY().toFloat() << "), ";
	std::cout << "B(" << B.getX().toFloat() << ", " << B.getY().toFloat() << "), ";
	std::cout << "C(" << C.getX().toFloat() << ", " << C.getY().toFloat() << ")";
	std::cout << "\n" <<std::endl;
	std::cout << "Point P is ";
	std::cout << "P(" << P.getX().toFloat() << ", " << P.getY().toFloat() << ")\n" << std::endl;
}

int main( void ) 
{
	Point		A(0.f, 0.f);
	Point		B(10.f, 30.f);
	Point		C(20.f, 0.f);
	Point		P(10.f, 15.f);

	Point		D(3.f, 5.f);
	Point		E(15.f, 30.f);
	Point		F(26.f, 7.f);
	Point		P2(30.f, 45.f);
	
	printData(A, B, C, P);
	if (bsp(A, B, C, P) == true)
		std::cout << "Point P is in the triangle ABC!" << std::endl;
	else
		std::cout << "Point P is not in the triangle ABC!" << std::endl;
	std::cout << std::endl;
	printData(D, E, F, P2);
		if (bsp(D, E, F, P2) == true)
		std::cout << "Point P2 is in the triangle DEF!" << std::endl;
	else
		std::cout << "Point P2 is not in the triangle DEF!" << std::endl;
	return 0;
}