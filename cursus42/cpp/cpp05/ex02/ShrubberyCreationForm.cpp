/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:36:47 by greg              #+#    #+#             */
/*   Updated: 2025/01/07 19:19:38 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat &target) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm::AForm(copy), _target(copy._target)
{
	*this = copy;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default destructor called." << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &op)
{
	if (this != &op)
		return *this;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat &executor) const
{
	if (executor.getgrade() > this->getexecgrade())
		throw (Bureaucrat::GradeTooLowException());
	else if(this->getsigned() == false)
		throw (AForm::AFormNotSignedException());
	else
	{
		executor.executeForm(*this);
		std::string		outfile = executor.getname() + "_shrubbery";
		std::ofstream	output(outfile.c_str());
		if (!output)
		{
			std::cerr << "Error opening file!" << std::endl;
			return;
		}

		output << "       _-_" << std::endl;
		output << "    /~~   ~~\\" << std::endl;
		output << " /~~         ~~\\" << std::endl;
		output << "{               }" << std::endl;
		output << " \\  _-     -_  /" << std::endl;
		output << "   ~  \\ //  ~" << std::endl;
		output << "_- -   | | _- _" << std::endl;
		output << "  _ -  | |   -_" << std::endl;
		output << "      // \\\\" << std::endl;
		output.close();
	}
}


std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &op)
{
	if (op.getsigned() == true)
		std::cout << "The form " << op.getname() << " is signed" << std::endl;
	else
		std::cout << "The form " << op.getname() << " is not signed" << std::endl;
	return out;
}


