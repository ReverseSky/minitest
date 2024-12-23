/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:36:48 by greg              #+#    #+#             */
/*   Updated: 2024/12/22 10:25:18 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	Span	array(10000);

	srand(time(NULL));
	try {
		array.addVarious(10);
		// array.addNumber(10);
		// array.addNumber(5);
		// array.addNumber(14);
		// array.addNumber(3);
		// array.addNumber(7);
	}
	catch(const std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << array.longestSpan() << std::endl;
	std::cout << array.shortestSpan() << std::endl;

	return 0;
}