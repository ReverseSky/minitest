/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:37:31 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 01:15:06 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{

public:
	AForm();
	AForm(std::string name, int signgrade, int execgrade);
	AForm(AForm const &copy);
	virtual ~AForm();
	
	AForm	&operator=(const AForm &op);
	
	std::string	getname() const;
	bool		getsigned() const;
	int			getsigngrade() const;
	int			getexecgrade() const;

	void		beSigned(Bureaucrat &signer);
	virtual void	execute(Bureaucrat & executor) const = 0;

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
	class AFormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

private:
	const std::string	_name;
	bool				_signed;
	const int			_signgrade;
	const int			_execgrade;
};

std::ostream	&operator<<(std::ostream & out, AForm const &op);

#endif