/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:27:27 by greg              #+#    #+#             */
/*   Updated: 2025/01/09 18:00:46 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() 
{
	Data originalData;

	std::cout << "Original Data size: " << originalData.getSize() << std::endl << std::endl;
	std::cout << "Original Data adress: " << &originalData << std::endl << std::endl;

	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "Serialized Data address: " << raw << std::endl << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Deserialized data adress: " << deserializedData << std::endl << std::endl;
	if (deserializedData == &originalData) 
		std::cout << "Deserialization successful: Deserialized data matches original data." << std::endl;
	else
		std::cout << "Deserialization failed: Pointers do not match." << std::endl;

	std::cout << "Deserialized Data size: " << deserializedData->getSize() << std::endl;

	return 0;
}
