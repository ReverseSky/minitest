/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:20:03 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 02:21:10 by greg             ###   ########.fr       */
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
	AForm *			shrub = NULL;
	AForm *			robot = NULL;
	AForm *			ppf = NULL;

	try {
		shrub = stagiaire->makeForm("ShrubberyCreationForm", *Paul);
		shrub->beSigned(*Paul);
		std::cout << std::endl;
		robot = stagiaire->makeForm("RobotomyRequestForm", *Pierre);
		robot->beSigned(*David);
		std::cout << std::endl;
		robot->execute(*Pierre);
		std::cout << std::endl;
		shrub->execute(*David);
		std::cout << std::endl;
		// ppf->execute(*David);
		std::cout << std::endl;
		ppf = stagiaire->makeForm("PresidentialPardonForm", *David);
		// ppf = stagiaire->makeForm("presidentiaf pardon", *Paul);
		std::cout << std::endl;
		ppf->beSigned(*David);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << *shrub << std::endl;
	std::cout << *robot << std::endl;

	delete ppf;
	delete robot;
	delete shrub;
	delete stagiaire;
	delete Paul;
	delete Pierre;
	delete David;
}