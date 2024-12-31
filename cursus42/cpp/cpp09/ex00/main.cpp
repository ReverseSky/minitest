/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:28:01 by greg              #+#    #+#             */
/*   Updated: 2024/12/24 03:04:02 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string		trim(const std::string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void	testInput(std::ifstream & file, int ac, char **av)
{
	std::string				name(av[1]);
	std::string				line;
	std::ifstream	lineTest;

	if (ac != 2)
		throw std::runtime_error("Error: Usage: ./btc [data.csv]");
	
	file.open(av[1], std::ifstream::in);
	if (!file.is_open())
		throw std::runtime_error("Error: Could not open file: " + name);
	
	lineTest.open(av[1], std::ifstream::in);
	while (getline(lineTest, line))
	{
		if (line.empty())
			throw std::runtime_error("Error: Empty line in input file.");
	}

}

int	main(int ac, char **av) {
	std::ifstream		file;
	BitcoinExchange *	exchange;
	
	try {
		testInput(file, ac, av);
		exchange = new BitcoinExchange(file, av);
	}
	catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	delete exchange;
	return 0;
}