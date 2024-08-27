/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:44:51 by greg              #+#    #+#             */
/*   Updated: 2024/08/26 14:02:22 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed	&operator=(const Fixed &op);

		Fixed	operator+(const Fixed &op) const;
		Fixed	operator-(const Fixed &op) const;
		Fixed	operator*(const Fixed &op) const;
		Fixed	operator/(const Fixed &op) const;
		Fixed	&operator++(void); //pre increment
		Fixed	operator++(int); // post increment
		Fixed	&operator--(void);
		Fixed	operator--(int);

		bool	operator>(Fixed const &op) const;
		bool	operator<(Fixed const &op) const;
		bool	operator>=(Fixed const &op) const;
		bool	operator<=(Fixed const &op) const;
		bool	operator==(Fixed const &op) const;
		bool	operator!=(Fixed const &op) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &			min(Fixed &a, Fixed &b);
		static Fixed const		&min(Fixed const &a, Fixed const &b);
		static Fixed &			max(Fixed &a, Fixed &b);
		static Fixed const &	max(Fixed const &a, Fixed const &b);

		private:
			int	_value;
			static const int	fractionnal_bits = 8;
			
	};

	std::ostream	&operator<<(std::ostream & out, Fixed const &fixe);

#endif