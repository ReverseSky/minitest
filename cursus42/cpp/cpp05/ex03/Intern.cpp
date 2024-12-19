/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:08:26 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 01:44:24 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called." << std::endl;
}
Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor called." << std::endl;
	*this = copy;
}

Intern::~Intern()
{
		std::cout << "Intern default destructor called." << std::endl;
}

Intern	&Intern::operator=(const Intern &op)
{
	if (this == &op)
		return *this;
	return *this;
}

AForm	*Intern::makeForm(std::string name, Bureaucrat &target) const
{
	AForm *form = NULL;
	AForm  *(Intern::*funcPtr[3])(Bureaucrat &target) const = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int i = 0;

	while (i < 3)
	{
		if (forms[i] == name)
		{
			form = (this->*funcPtr[i])(target);
			std::cout << "Intern created " << name << " form." << std::endl;
			return form;
		}
		i++;
	}
	std::cout << "Intern can't create " << name << " form because of : ";
	throw (Intern::WrongNameException());
	return NULL;
}

AForm *Intern::makePresidential(Bureaucrat &target) const
{
	AForm *form = new PresidentialPardonForm(target);
	return form;
}

AForm *Intern::makeRobotomy(Bureaucrat &target) const
{
	AForm *form = new RobotomyRequestForm(target);
	return form;
}

AForm *Intern::makeShrubbery(Bureaucrat &target) const
{
	AForm *form = new ShrubberyCreationForm(target);
	return form;
}

const char *	Intern::WrongNameException::what() const throw() {
	return ("Invalid form name.");
}