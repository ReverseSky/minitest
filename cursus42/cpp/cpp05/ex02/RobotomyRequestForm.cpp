/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:18:02 by greg              #+#    #+#             */
/*   Updated: 2025/01/08 17:27:08 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(Bureaucrat &target) : AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm::AForm(copy), _target(copy._target)
{
	*this = copy;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default destructor called." << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &op)
{
	if (this != &op)
		this->_target = op._target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat &executor) const
{
	if (executor.getgrade() > this->getexecgrade())
		throw (Bureaucrat::GradeTooLowException());
	else if(this->getsigned() == false)
		throw (AForm::AFormNotSignedException());
	else
	{
		std::cout << "Some drilling noise" << std::endl;
		srand(time(NULL));
		int	nb = rand() % 100 + 1;
		if (nb % 2 == 0)
			std::cout << executor.getname() << " has been robotomized." << std::endl;
		else
			std::cout << "Robotomy of " << executor.getname() << " failed." << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &op)
{
	if (op.getsigned() == true)
		std::cout << "The form " << op.getname() << " is signed" << std::endl;
	else
		std::cout << "The form " << op.getname() << " is not signed" << std::endl;
	return out;
}


