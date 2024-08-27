/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:44:46 by greg              #+#    #+#             */
/*   Updated: 2024/08/26 13:54:55 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	this->_value = copy.getRawBits();
}

Fixed::Fixed(const int i)
{
	this->_value = i << this->fractionnal_bits;
}
Fixed::Fixed(const float f)
{
	this->_value = roundf(f * (1 << this->fractionnal_bits));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &op)
{
	this->_value = op.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &op) const
{
	return Fixed(this->toFloat() + op.toFloat());
}

Fixed	Fixed::operator-(Fixed const &op) const
{
	return Fixed(this->toFloat() - op.toFloat());
}

Fixed	Fixed::operator*(Fixed const &op) const
{
	return Fixed(this->toFloat() * op.toFloat());
}

Fixed	Fixed::operator/(Fixed const &op) const
{
	if (op.getRawBits() == 0)
		throw std::logic_error("Division by zero!");
	return Fixed(this->toFloat() / op.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	
	operator++();
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	
	operator--();
	return tmp;
}

bool	Fixed::operator>(Fixed const &op) const
{
	return (this->_value > op.getRawBits());
}

bool	Fixed::operator<(Fixed const &op) const
{
	return (this->_value < op.getRawBits());
}
bool	Fixed::operator>=(Fixed const &op) const
{
	return (this->_value >= op.getRawBits());
}

bool	Fixed::operator<=(Fixed const &op) const
{
	return (this->_value <= op.getRawBits());
}

bool	Fixed::operator==(Fixed const &op) const
{
	return (this->_value == op.getRawBits());
}

bool	Fixed::operator!=(Fixed const &op) const
{
	return (this->_value != op.getRawBits());
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixe)
{
	out  << fixe.toFloat();
	return out;
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt() const
{
	return (this->_value >> Fixed::fractionnal_bits);
}

float Fixed::toFloat() const
{
	return ((float)this->_value / (float)(1 << fractionnal_bits));
}


Fixed &	Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed const &	Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &	Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return a;
	return b;
}