/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:28:13 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/20 14:18:18 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"

int	main(void)
{
	Phonebook	Phonebook;
	std::string	line;
	std::string search = "SEARCH";
	std::string search2 = "search";
	std::string add = "ADD";
	std::string add2 = "add";
	std::string	exit = "EXIT";
	std::string	exit2 = "exit";


	while (1)
	{
		std::cout << "Type ADD SEARCH or EXIT" << std::endl;
		std::getline(std::cin, line);
		if ((!line.compare(add)) || (!line.compare(add2)))
			Phonebook.add_contact();
		else if ((!line.compare(search)) || (!line.compare(search2)))
			Phonebook.search_contact();
		else if ((!line.compare(exit)) || (!line.compare(exit2)))
		{
			std::cout << "Exiting Phonebook... Goodbye!" << std::endl;
			break;
		}
		system("clear");
	}
	return(0);
}