/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:20:03 by greg              #+#    #+#             */
/*   Updated: 2024/12/18 19:21:28 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat *	David = new Bureaucrat("David", 2);
	Bureaucrat *	Pierre = new Bureaucrat("Pierre", 10);
	Bureaucrat *	Paul = new Bureaucrat("Paul", 65);
	std::cout << std::endl;

	AForm *			shru = new ShrubberyCreationForm(*Pierre);
	AForm *			robot = new RobotomyRequestForm(*David);
	std::cout << std::endl;

	try {
		robot->beSigned(*Paul);
		std::cout << std::endl;
		shru->beSigned(*Pierre);
		std::cout << std::endl;
		robot->execute(*David);
		std::cout << std::endl;
		shru->execute(*David);
		std::cout << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << *shru << std::endl;
	std::cout << *robot << std::endl;

	delete robot;
	delete shru;
	delete Paul;
	delete Pierre;
	delete David;
}