/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:20:03 by greg              #+#    #+#             */
/*   Updated: 2025/01/08 17:40:17 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat *	David = new Bureaucrat("David", 2);
	Bureaucrat *	Pierre = new Bureaucrat("Pierre", 10);
	Bureaucrat *	Paul = new Bureaucrat("Paul", 65);
	std::cout << std::endl;
	Intern *		stagiaire = new Intern();
	std::cout << std::endl;
	AForm *			shru = NULL;
	AForm *			robot = NULL;
	AForm *			ppf = NULL;

	try {
		shru = stagiaire->makeForm("ShrubberyCreationForm", *Paul);
		std::cout << std::endl;
		robot = stagiaire->makeForm("RobotomyRequestForm", *Pierre);
		std::cout << std::endl;
		ppf = stagiaire->makeForm("PresidentialPardonForm", *David);
		// ppf = stagiaire->makeForm("presidentiaf pardon", *Paul);

		std::cout << std::endl;

		Paul->signForm(*shru);
		Pierre->signForm(*robot);
		David->signForm(*ppf);

		std::cout << std::endl;
		Pierre->executeForm(*robot);
		std::cout << std::endl;
		Paul->executeForm(*shru);
		std::cout << std::endl;
		David->executeForm(*ppf);
		std::cout << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << *shru << std::endl;
	std::cout << *robot << std::endl;

	delete ppf;
	delete robot;
	delete shru;
	delete stagiaire;
	delete Paul;
	delete Pierre;
	delete David;
}