/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 07:12:03 by greg              #+#    #+#             */
/*   Updated: 2024/12/22 10:25:08 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0), _size(0)
{
}
Span::Span(unsigned int N) : _maxSize(N), _size(0)
{

}

Span::Span(const Span &copy)
{
	this->_array = copy._array;
	this->_maxSize = copy._maxSize;
	this->_size = copy._size;
}
Span::~Span()
{
}

Span	&Span::operator=(const Span &op)
{
	if (this != &op)
	{
		this->_array = op._array;
		this->_maxSize = op._maxSize;
		this->_size = op._size;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (this->_size == this->_maxSize)
		throw (Span::MaxNumbersException());
	this->_array.push_back(n);
	this->_size++;
}

void	Span::addVarious(int n)
{
	if (this->_size + n > this->_maxSize) {
		std::cout << "Can't add " << n << " elements to the array, the max_size will be reached." << std::endl; return;
	}
	
	int nb = 0;
	
	for (int i = 0; i < n; i++) {
		nb = rand() % 1000 + 1;
		this->addNumber(nb);
		std::cout << this->_size << " / " << this->_maxSize << " : " << nb << std::endl;
	}
}


int					Span::shortestSpan() 
{
	std::vector<int>	array(this->_array);
	
	if (!array.size())
		throw Span::NoNumberException();
	if (array.size() == 1)
		throw Span::OneNumberException();

	int		min = __INT_MAX__;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite = 	array.end();
	
	std::sort(array.begin(), array.end());
	for (it = array.begin(); (it + 1) != ite; it++) 
	{
		if ((*(it + 1) - *it) < min) 
			min = (*(it + 1) - *it);
	}
	return min;
}

int					Span::longestSpan() const 
{
	if (!this->_array.size())
		throw Span::NoNumberException();
	if (this->_array.size() == 1)
		throw Span::OneNumberException();
	int	max = *std::max_element(this->_array.begin(), this->_array.end());
	int	min = *std::min_element(this->_array.begin(), this->_array.end());

	return max - min;
}


const char *		Span::MaxNumbersException::what() const throw() {
	return "Error : max size reached";
}

const char *	Span::NoNumberException::what() const throw() {
	return "Error : array is empty.";
}

const char *	Span::OneNumberException::what() const throw() {
	return "Error impossible to compare : array contain only one number.";
}