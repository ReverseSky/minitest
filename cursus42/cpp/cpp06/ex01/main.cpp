/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:27:27 by greg              #+#    #+#             */
/*   Updated: 2024/12/29 14:16:27 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data originalData;

    std::cout << "Original Data size: " << originalData.getSize() << std::endl;

    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized Data address: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);

    if (deserializedData == &originalData) {
        std::cout << "Deserialization successful: Deserialized data matches original data." << std::endl;
    } else {
        std::cout << "Deserialization failed: Pointers do not match." << std::endl;
    }

    std::cout << "Deserialized Data size: " << deserializedData->getSize() << std::endl;

    return 0;
}