/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 07:14:48 by greg              #+#    #+#             */
/*   Updated: 2024/12/22 07:17:37 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <stdexcept>

class NoValueException : public std::exception 
{
	public:
		virtual const char *	what() const throw();
};

template <typename T>
int	easyfind(const T &array, int val);

#endif