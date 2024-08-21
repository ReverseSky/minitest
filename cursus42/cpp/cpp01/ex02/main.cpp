/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:28:13 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/21 13:45:56 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "address of str : " << &string << std::endl;
	std::cout << "addres held by ptr : " << stringPTR << std::endl;
	std::cout << "adress held by ref : " << &stringREF << std::endl;

	std::cout << "value of str : " << string << std::endl;
	std::cout << "value of pointer : " << *stringPTR << std::endl;
	std::cout << "value of reference : " << stringREF << std::endl;
}