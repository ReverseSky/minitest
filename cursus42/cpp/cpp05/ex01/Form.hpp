/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:37:31 by greg              #+#    #+#             */
/*   Updated: 2025/01/07 17:08:07 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{

public:
	Form();
	Form(std::string name, int signgrade, int execgrade);
	Form(Form const &copy);
	~Form();
	
	Form	&operator=(const Form &op);

	std::string	getname() const;
	bool		getsigned() const;
	int			getsigngrade() const;
	int			getexecgrade() const;

	void		beSigned(Bureaucrat &signer);

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
	const std::string	_name;
	bool				_signed;
	const int			_signgrade;
	const int			_execgrade;
};

std::ostream	&operator<<(std::ostream & out, Form const &op);

#endif