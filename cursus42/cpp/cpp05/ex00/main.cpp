/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:20:03 by greg              #+#    #+#             */
/*   Updated: 2025/01/09 14:48:11 by grobledo         ###   ########.fr       */
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
		David = new Bureaucrat("David", 0);
		std::cout << "test" << std::endl;
		std::cout << *David << std::endl;
		std::cout << "try to demote David." << std::endl;
		David->demote();
		std::cout << *David << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}

	std::cout<<std::endl;

	try 
	{
		David = new Bureaucrat("David", 151);
		std::cout << "test" << std::endl;
		std::cout << *David << std::endl;
		std::cout << "try to demote David." << std::endl;
		David->demote();
		std::cout << *David << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try 
	{
		David = new Bureaucrat("David", 5);
		std::cout << *David << std::endl;
		std::cout << "try to demote David." << std::endl;
		David->demote();
		std::cout << *David << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

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

	std::cout << std::endl;

	try {
		Paul = new Bureaucrat("Paul", 100);
		std::cout << *Paul << std::endl;
		std::cout << "try to promote Paul." << std::endl;
		Paul->demote();
		std::cout << *Paul << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try {
		std::cout << "Set Paul grade to 150." << std::endl;
		Paul->setgrade(150);
		std::cout << *Paul << std::endl;
		std::cout << "try to promote Paul." << std::endl;
		Paul->demote();
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *Paul << std::endl;

	std::cout << std::endl;

	delete Paul;
	delete Pierre;
	delete David;
	return 0;
}