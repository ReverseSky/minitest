/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:20:03 by greg              #+#    #+#             */
/*   Updated: 2025/01/07 19:36:29 by grobledo         ###   ########.fr       */
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
		robot->execute(*Pierre);
		std::cout << std::endl;
		shru->execute(*Paul);
		std::cout << std::endl;
		ppf->execute(*David);
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