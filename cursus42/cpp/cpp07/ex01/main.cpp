/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:48:15 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 18:59:15 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template<typename T>
void	iter(T *adress, int lenght, void (*fct)(T &var))
{
	for(int i = 0; i < lenght ; i++)
		fct(adress[i]);
}

template<typename T>
void	printValue(T &val)
{
	std::cout << val;
}

void ft_toupper(char &array)
{
	array = std::toupper(static_cast<unsigned char>(array));
}

int	main()
{
	char	array[] = {'a', 'b', 'c', 'd'};

	iter(array, 4, printValue<char>);
	std::cout << std::endl;
	iter(array, 4, ft_toupper);
	iter(array, 4, printValue<char>);
	std::cout << std::endl;
}