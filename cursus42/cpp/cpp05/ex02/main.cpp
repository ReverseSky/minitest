/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:20:03 by greg              #+#    #+#             */
/*   Updated: 2025/01/08 17:23:52 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat	*David = new Bureaucrat("David", 2);
	Bureaucrat	*Pierre = new Bureaucrat("Pierre", 10);
	Bureaucrat	*Paul = new Bureaucrat("Paul", 65);
	std::cout << std::endl;
	
	AForm		*shru = new ShrubberyCreationForm(*Paul);
	AForm		*robot = new RobotomyRequestForm(*Pierre);
	AForm		*pres = new PresidentialPardonForm(*David);
	std::cout << std::endl;

	try {
		Paul->signForm(*shru);
		std::cout << std::endl;
		Pierre->signForm(*robot);
		std::cout << std::endl;
		David->signForm(*pres);
		std::cout << std::endl;
		Pierre->executeForm(*robot);
		std::cout << std::endl;
		David->executeForm(*pres);
		std::cout << std::endl;
		Paul->executeForm(*shru);
		std::cout << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << *shru << std::endl;
	std::cout << *robot << std::endl;
	std::cout << *pres << std::endl;
	std::cout << std::endl;

	delete robot;
	delete shru;
	delete pres;
	delete Paul;
	delete Pierre;
	delete David;
}