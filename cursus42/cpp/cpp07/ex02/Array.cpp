/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 04:57:34 by greg              #+#    #+#             */
/*   Updated: 2024/12/22 06:38:07 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new(T[0])), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->_array[n] = 0;
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	*this = copy;
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}


template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &op)
{
	if (this != &op)
	{
		delete [] this->_array;
		this->_array = new T[op._size];
		this->_size = op._size;
		for (int i = 0; i < op._size; i++)
			this->_array[i] = op._array[i];
	}
	return *this;
}

template <class T>
T	Array<T>::operator[](int n) const
{
	T	Element;

	if (n > _size - 1)
		throw (Array::OutOfBoundException());
	Element = this->_array[n];
	return	Element;
}


template <class T>
T	&Array<T>::operator[](int n)
{
	if (n > _size - 1)
		throw (Array::OutOfBoundException());
	return this->_array[n];
}

template <class T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return ("Index is out of bound.");
}

template <class T>
int	Array<T>::size() const
{
	return this->_size;
}