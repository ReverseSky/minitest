/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:27:27 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 18:03:40 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main() {
	Data *		data = new Data;
	uintptr_t	raw;

	std::cout << "Data : " << data << std::endl;

	raw = Serializer::serialize(data);

	std::cout << "Data Serialized : " << raw << std::endl;

	data = Serializer::deserialize(raw);

	std::cout << "Data unserialized : " << data << std::endl;

	delete data;
	return 0;
}