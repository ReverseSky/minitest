/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:06:58 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 17:30:01 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Data;

class Serializer
{
public:
	static uintptr_t	serialize(Data* ptr);
	static	Data		*deserialize(uintptr_t raw);

private:

	Serializer();
	Serializer(const Serializer &copy);
	~Serializer();
};




#endif