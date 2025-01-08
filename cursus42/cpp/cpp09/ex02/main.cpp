/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:57:51 by greg              #+#    #+#             */
/*   Updated: 2025/01/08 18:50:59 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 2)
		return std::cout << "Error: Usage: ./sort [int sequence]" << std::endl, 1;
	
	std::vector<int>	input;
	int					nb;
	int					i;
	
	for (i = 1; av[i] != NULL; i++) {
		for (int j = 0; av[i][j] != '\0'; j++)
			if (!isdigit(av[i][j]))
				return std::cout << "Error." << std::endl, 1;
		nb = atoi(av[i]);
		if (nb < 0)
			return std::cout << "Error." << std::endl, 1;
		input.push_back(nb);
	}

	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite = input.end();

	std::cout << "Before: ";
	for (it = input.begin(); it != ite; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	
	PmergeMe	instance(input, i - 1);

	return 0;
}