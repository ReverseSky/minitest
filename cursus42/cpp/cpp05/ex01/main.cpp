/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:20:03 by greg              #+#    #+#             */
/*   Updated: 2025/01/09 14:49:27 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() 
{
	Bureaucrat 		*David = NULL;
	Bureaucrat 		*Pierre = NULL;
	Form 			*simpleDoc = NULL;

	try 
	{
		David = new Bureaucrat("David", 55);
		simpleDoc = new Form("Simple Document", 50, 50);
		David->signForm(*simpleDoc);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	
	try 
	{
		Pierre = new Bureaucrat("Pierre", 35);
		Pierre->signForm(*simpleDoc);
		David->promote();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout << *simpleDoc << std::endl;
	delete David;
	delete Pierre;
	delete simpleDoc;
}