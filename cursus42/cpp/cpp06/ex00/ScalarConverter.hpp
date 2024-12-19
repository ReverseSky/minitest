/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:23:06 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 02:35:05 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <limits.h>
#include <float.h>
#include <cstdlib>

class ScalarConverter
{

public:
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter();

	ScalarConverter	&operator=(ScalarConverter const &op);
	static void	convert(std::string param);
private:
	ScalarConverter();

};




#endif