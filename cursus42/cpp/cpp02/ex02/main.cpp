/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:18 by greg              #+#    #+#             */
/*   Updated: 2024/08/27 12:22:18 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "+ operator b + d : " << (b + d) << std::endl;
	std::cout << "- operator b - c: " << (b - c) << std::endl;
	std::cout << "* operator b * c: " << (b * c) << std::endl;
	std::cout << "* operator b / c: " << (b / c) << std::endl;

	if (c < b)
		std::cout << "c lower than b" << std::endl;
	if (b > c)
		std::cout << "b greater than c" << std::endl;
	if (b >= d)
		std::cout << "b equal d" << std::endl;
	if (b <= d)
		std::cout << "b equal d" << std::endl;
	if (b == d)
		std::cout << "b equal d" << std::endl;
	if (b != c)
		std::cout << "b different c" << std::endl;
	std::cout << a << " " << ++a << std::endl;
	std::cout << a << " " << --a << std::endl;
	std::cout << a << " " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << a << " " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << Fixed::min(b, c) << std::endl;
	std::cout << Fixed::max(b, c) << std::endl;
	return 0;
}

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;
	
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }	