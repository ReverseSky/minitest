/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:16:40 by greg              #+#    #+#             */
/*   Updated: 2024/12/18 19:02:31 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_hpp
#define ROBOTOMYREQUESTFORM_hpp

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(Bureaucrat &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &op);
	
	void	execute(Bureaucrat & executor) const;

private:
	Bureaucrat &_target;
};

std::ostream	&operator<<(std::ostream & out, RobotomyRequestForm const &op);

#endif