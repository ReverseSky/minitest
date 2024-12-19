/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:08:20 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 01:31:29 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class Bureaucrat;

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();

	Intern	&operator=(const Intern &op);

	AForm	*makeForm(std::string name, Bureaucrat &target) const;

	class WrongNameException : public std::exception {
		public:
			virtual const char *	what() const throw();
	};

	private:
		AForm *makePresidential(Bureaucrat & target) const;
		AForm *makeRobotomy(Bureaucrat & target) const;
		AForm *makeShrubbery(Bureaucrat & target) const;
};

#endif