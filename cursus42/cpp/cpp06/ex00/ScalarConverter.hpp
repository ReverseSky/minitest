/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:23:06 by greg              #+#    #+#             */
/*   Updated: 2025/01/09 19:37:31 by grobledo         ###   ########.fr       */
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
	ScalarConverter	&operator=(ScalarConverter const &op);
	
	static void	convert(std::string param);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter();


};




#endif