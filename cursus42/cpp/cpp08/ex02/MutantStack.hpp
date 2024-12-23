/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 10:36:49 by greg              #+#    #+#             */
/*   Updated: 2024/12/22 10:40:53 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <iostream>
#include <string>
#include <stack>
#include <list>

typedef std::string str;

template<class T>
class MutantStack : public std::stack<T> 
{
	public:
		MutantStack();
		MutantStack(MutantStack const &copy);
		~MutantStack();

		MutantStack<T> &	operator=(MutantStack<T> const &op);

		typedef	typename std::stack<T>::container_type::iterator	iterator;
		iterator			begin();
		iterator			end();
	private:
};

template<typename T>
MutantStack<T>::MutantStack() 
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &copy) : std::stack<T>(copy) 
{
}

template<typename T>
MutantStack<T>::~MutantStack() 
{
}

template<typename T>
MutantStack<T> &	MutantStack<T>::operator=(MutantStack<T> const &op) 
{
	if (*this != &op) 
		*this = op;
	return *this;
}


template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() 
{
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() 
{
	return std::stack<T>::c.end();
}

#endif