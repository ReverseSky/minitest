/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 04:57:44 by greg              #+#    #+#             */
/*   Updated: 2024/12/22 06:26:37 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

template<typename T>
class Array
{

public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	~Array();

	Array	&operator=(const Array &op);
	T	operator[](int n) const;
	T	&operator[](int n);
	int	size() const;


	class OutOfBoundException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
private:
	T	*_array;
	T	_size;
};





#endif