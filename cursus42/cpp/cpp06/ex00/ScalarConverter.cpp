/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:23:09 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 16:57:14 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	charConvert(std::string param)
{
	std::cout << "char: " << param[0] << std::endl;
	std::cout << "int: " << static_cast<int>(param[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(param[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(param[0]) << std::endl;
}

static void	minInfConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "int: " << __FLT_MIN__ << std::endl;
	std::cout << "int: " << __DBL_MIN__ << std::endl;
}

static void	maxInfConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "int: " << __FLT_MAX__ << std::endl;
	std::cout << "int: " << __DBL_MAX__ << std::endl;
}

static void	nanConvert() 
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static void	intConvert(std::string param)
{
	int n = atoi(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	if (n < 32 || n == 127)
		std::cout << "char: non displayable character" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

static void	floatConvert(std::string param)
{
	float n = atof(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	if (n < 32 || n == 127)
		std::cout << "char: non displayable character" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << n << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}
static void	doubleConvert(std::string param)
{
	float n = atof(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	if (n < 32 || n == 127)
		std::cout << "char: non displayable character" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << n << std::endl;
}



static void	error()
{
	std::cout << "Error: Impossible to print or input not convertable" << std::endl;
}

static void	checkInput(std::string param)
{
	if (std::isprint(param[0]) && !std::isdigit(param[0]))
	{
		if (param.length() == 1)
			charConvert(param);
		else if (param == "-inf" || param == "-inff")
			minInfConvert();
		else if (param == "+inf" || param == "+inff")
			maxInfConvert();
		else if (param == "nan" || param == "nanf")
			nanConvert();
		else
			error();
	}
	else if (param[param.length() - 1] == 'f')
	{
		unsigned long int i = 0;
		while (i < param.length() - 1 && (std::isdigit(param[i]) || param[i] == '.'))
			i++;
		if (i == param.length() - 1)
			floatConvert(param);
		else
		{
			std::cout << "test" << std::endl;
			error();
		}
			
	}
	else if (param.find('.') != std::string::npos)
	{
		unsigned long int i = 0;
		while (std::isdigit(param[i]) || param[i] == '.')
			i++;
		if (i == param.length())
			doubleConvert(param);
		else
			error();
	}
	else if (std::isdigit(param[0]))
	{
		long unsigned int	i = 0;
		while (std::isdigit(param[i]))
			i++;
		if (i == param.length())
			intConvert(param);
		else
			error();
	}
	else
		error();
}

void	ScalarConverter::convert(std::string param)
{
	checkInput(param);
}