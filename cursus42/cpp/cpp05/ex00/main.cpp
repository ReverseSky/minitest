/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:20:03 by greg              #+#    #+#             */
/*   Updated: 2024/12/11 08:13:13 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() 
{
	Bureaucrat *David = NULL;
	Bureaucrat *Pierre = NULL;
	Bureaucrat *Paul = NULL;

	try 
	{
		David = new Bureaucrat("David", 5);
		std::cout << *David << std::endl;
		std::cout << "try to demote David." << std::endl;
		David->demote();
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *David << std::endl;

	try {
		Pierre = new Bureaucrat("Pierre", 1);
		std::cout << *Pierre << std::endl;
		std::cout << "try to promote Pierre." << std::endl;
		Pierre->promote();
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *Pierre << std::endl;

	try {
		Paul = new Bureaucrat("Paul", 100);
		std::cout << *Paul << std::endl;
		std::cout << "try to promote Paul." << std::endl;
		Paul->promote();
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *Paul << std::endl;

	delete Paul;
	delete Pierre;
	delete David;
	return 0;
}