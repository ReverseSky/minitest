/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:37:23 by greg              #+#    #+#             */
/*   Updated: 2024/12/18 19:05:19 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : _name(NULL), _signed(false), _signgrade(150), _execgrade(150)
{
	std::cout << "AForm default constructor called." << std::endl;
}
AForm::AForm(std::string name, int signgrade, int execgrade) : _name(name), _signed(false), _signgrade(signgrade), _execgrade(execgrade)
{
	std::cout << "AForm base constructor called for : " << getname() << ". It need grade " << getsigngrade() << " to be signed and " << execgrade << " to be executed." << std::endl;
}
AForm::AForm(AForm const &copy) : _name(copy.getname()),  _signed(copy.getsigned()), _signgrade(copy.getsigngrade()), _execgrade(copy.getexecgrade())
{
	*this = copy;
}

AForm::~AForm()
{
	std::cout << "AForm base destructor called." << std::endl;
}

AForm	&AForm::operator=(const AForm &op)
{
	if (this != &op)
		this->_signed = op.getsigned();
	return *this;
}

std::ostream	&operator<<(std::ostream & out, AForm const &op)
{
	out << "Form " << op.getname() << " need to bee minimum grade " << op.getsigngrade() << " to be signed and " << op.getexecgrade() << " to be exectuted." << std::endl;
	if (op.getsigned() == true)
		std::cout << "This form is signed" << std::endl;
	else
		std::cout << "This form is not signed" << std::endl;
	return out;
}

std::string	AForm::getname() const
{
	return this->_name;
}

bool	AForm::getsigned() const
{
	return this->_signed;
}

int	AForm::getsigngrade() const
{
	return this->_signgrade;
}

int	AForm::getexecgrade() const
{
	return this->_execgrade;
}

void	AForm::beSigned(Bureaucrat &signer)
{
	if (signer.getgrade() > this->_signgrade)
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getsigned() == false)
	{
		this->_signed = true;
		std::cout << this->getname() << " Form was signed by " << signer.getname() << std::endl;
	}
	else
		std::cout << "The form " <<  this->_name << " is already signed." << std::endl;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade to high.");
}
const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char *AForm::AFormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
};