/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 07:14:52 by greg              #+#    #+#             */
/*   Updated: 2024/12/22 08:00:04 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP_
#define EASYFIND_TPP_

#include "easyfind.hpp"

const char *	NoValueException::what() const throw() {
	return "No occurrence found in the container.";
}

template <typename T>
int	easyfind(T const &array, int val)
{
	typename T::const_iterator	it;
	typename T::const_iterator	ite = array.end();

	for (it = array.begin(); it != ite; it++)
	{
		if (*it == val)
			return *it;
	}
	throw NoValueException();
}

#endif