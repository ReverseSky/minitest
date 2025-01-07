/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:36:47 by greg              #+#    #+#             */
/*   Updated: 2025/01/07 18:16:34 by grobledo         ###   ########.fr       */
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
	out << "Form name : " << op.getname() << " need grade " << op.getsigngrade() << " to be signed and " << op.getexecgrade() << " to be executed" <<std::endl;
	std::cout << "The document is ";
	if (op.getsigned() == false)
		std::cout << "not ";
	std::cout << "signed." << std::endl;
	return (out);
}


