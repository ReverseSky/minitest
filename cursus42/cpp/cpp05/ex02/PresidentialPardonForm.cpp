/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:09:34 by greg              #+#    #+#             */
/*   Updated: 2025/01/07 19:19:29 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(Bureaucrat &target) : AForm::AForm("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm::AForm(copy), _target(copy._target)
{
	*this = copy;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default destructor called." << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &op)
{
	if (this != &op)
		this->_target = op._target;
	return *this;
}

Bureaucrat &PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat &executor) const
{
	if (executor.getgrade() > this->getexecgrade())
		throw (Bureaucrat::GradeTooLowException());
	else if(this->getsigned() == false)
		throw (AForm::AFormNotSignedException());
	else
	{
		executor.executeForm(*this);
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &op)
{
	if (op.getsigned() == true)
		std::cout << "The form " << op.getname() << " is signed" << std::endl;
	else
		std::cout << "The form " << op.getname() << " is not signed" << std::endl;
	return out;
}


