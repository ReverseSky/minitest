/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:46:21 by greg              #+#    #+#             */
/*   Updated: 2024/12/29 13:51:55 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error, input must be : ./RPN \"expression\"" << std::endl; 
		return 1;
	}

	try
	{
		RPN	instance(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}