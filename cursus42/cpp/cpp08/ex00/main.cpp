/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 07:51:33 by greg              #+#    #+#             */
/*   Updated: 2024/12/22 08:04:26 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"

int	main()
{
	std::list<int>	lst;
	int				res;

	lst.push_back(2);
	lst.push_back(12);
	lst.push_back(25);
	lst.push_back(42);
	lst.push_back(4);

	std::cout << "test with bad value." << std::endl;

	try 
	{
		res = easyfind(lst, 28);
		std::cout << "Occurence found at index ; " << res << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "test with an occurence." << std::endl;
		try 
	{
		res = easyfind(lst, 42);
		std::cout << "Occurence found : " << res << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}