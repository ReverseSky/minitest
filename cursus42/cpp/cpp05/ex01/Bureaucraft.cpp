/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucraft.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:23:25 by greg              #+#    #+#             */
/*   Updated: 2024/12/17 16:25:39 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat base constructor called for : " << name;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << " and grade " << grade << "." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &op)
{
	if (this != &op)
		this->_grade = op._grade;
	return *this;
}

std::ostream	&operator<<(std::ostream & out, Bureaucrat const &op)
{
	out << op.getname() << ", bureaucrat grade " << op.getgrade();
	return out;
}

std::string	Bureaucrat::getname() const
{
	return	this->_name;
}

int	Bureaucrat::getgrade() const
{
	return	this->_grade;
}

void	Bureaucrat::promote()
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::demote()
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getname() << "." << std::endl;
	}
	catch( Form::GradeTooLowException & e)
	{
		std::cout << this->_name << " couldn't sign " << form.getname() << " because " << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}