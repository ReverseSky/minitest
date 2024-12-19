/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:06:00 by greg              #+#    #+#             */
/*   Updated: 2024/12/18 18:47:05 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_hpp
#define PRESIDENTIALPARDONFORM_hpp


#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(Bureaucrat &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(PresidentialPardonForm const &op);

	Bureaucrat &getTarget()const;
	
	void	execute(Bureaucrat &executor) const;

private:
	Bureaucrat &_target;
};

std::ostream	&operator<<(std::ostream & out, PresidentialPardonForm const &op);

#endif