/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 07:12:06 by greg              #+#    #+#             */
/*   Updated: 2024/12/22 09:52:48 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unistd.h>

class Span
{

public:
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	~Span();

	Span	&operator=(const Span &op);

	void	addNumber(int n);
	void	addVarious(int n);
	int		shortestSpan();
	int		longestSpan() const;

	class MaxNumbersException : public std::exception 
	{
		public:
			virtual const char *	what() const throw();
	};

	class NoNumberException : public std::exception 
	{
		public:
			virtual const char *	what() const throw();
	};

	class OneNumberException : public std::exception 
	{
		public:
			virtual const char *	what() const throw();
	};

private:
	std::vector<int>	_array;
	unsigned int		_maxSize;
	unsigned int		_size;
};

#endif