/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:22:01 by greg              #+#    #+#             */
/*   Updated: 2025/01/07 18:50:57 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <climits>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &copy);
	~Bureaucrat();
	
	Bureaucrat	&operator=(const Bureaucrat &op);
	
	std::string	getname() const;
	int			getgrade() const;
	void		setgrade(int grade);

	void		promote();
	void		demote();
	void		signForm(AForm &form);
	void		executeForm(AForm const & form);

	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char	*what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char	*what() const throw();
	};

private:
	std::string _name;
	int			_grade;
};

std::ostream	&operator<<(std::ostream & out, Bureaucrat const &op);

#endif