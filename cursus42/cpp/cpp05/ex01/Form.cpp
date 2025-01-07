/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:37:23 by greg              #+#    #+#             */
/*   Updated: 2025/01/07 17:35:32 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : _name(NULL), _signed(false), _signgrade(150), _execgrade(150)
{
	std::cout << "Form default constructor called." << std::endl;
}
Form::Form(std::string name, int signgrade, int execgrade) : _name(name), _signed(false), _signgrade(signgrade), _execgrade(signgrade - 1)
{
	std::cout << "Form base constructor called for : " << getname() << ". It need grade " << getsigngrade() << " to be signed and " << execgrade << " to be executed." << std::endl;
}
Form::Form(Form const &copy) : _name(copy.getname()),  _signed(copy.getsigned()), _signgrade(copy.getsigngrade()), _execgrade(copy.getexecgrade())
{
	*this = copy;
}

Form::~Form()
{
	std::cout << "Form base destructor called." << std::endl;
}

Form	&Form::operator=(const Form &op)
{
	if (this != &op)
		this->_signed = op.getsigned();
	return *this;
}

std::ostream	&operator<<(std::ostream & out, Form const &op)
{
	if (op.getsigned() == true)
		std::cout << "This form is signed" << std::endl;
	else
		std::cout << "This form is not signed" << std::endl;
	return out;
}

std::string	Form::getname() const
{
	return this->_name;
}

bool	Form::getsigned() const
{
	return this->_signed;
}

int	Form::getsigngrade() const
{
	return this->_signgrade;
}

int	Form::getexecgrade() const
{
	return this->_execgrade;
}

void	Form::beSigned(Bureaucrat &signer)
{
	if (signer.getgrade() > this->_signgrade)
	{
		std::cout << signer.getname() << " couldn't sign " << this->getname() << " because : ";
		throw(Bureaucrat::GradeTooLowException());
	}
	else if (this->getsigned() == false)
	{
		this->_signed = true;
	}
	else
		std::cout << "The form " <<  this->_name << " is already signed." << std::endl;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade to high.");
}
const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}
