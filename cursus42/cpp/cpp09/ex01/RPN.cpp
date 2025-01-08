/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:21:04 by greg              #+#    #+#             */
/*   Updated: 2025/01/08 17:32:16 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(char *input)
{
	int	first;
	int	next;

	int	result = 0;
	int	digit = 0;
	int	sign = 0;
	
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ' || input[i] == '\t')
			i++;
		if (isdigit(input[i]))
			digit++;
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			sign++;
		else
			throw std::runtime_error("Error: Invalid character in input");
	}
	if (sign != digit - 1)
		throw std::runtime_error("Error : Wrong expression");
	for(int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ' || input[i] == '\t')
			continue;
		else if (isdigit(input[i]))
			this->_stack.push(input[i] - '0');
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			if (this->_stack.size() < 2)
				throw std::runtime_error("Error: Not enough operands for operation");
			next = this->_stack.top();
			this->_stack.pop();
			first = this->_stack.top();
			this->_stack.pop();
			switch (input[i])
			{
				case '+':
				{
					result = first + next;
					break;
				}
				case '-':
				{
					result = first - next;
					break;
				}
				case '*':
				{
					result = first * next;
					break;
				}
				case '/':
				{
					result = first / next;
					break;
				}
				default:
					break;
			}
			this->_stack.push(result);
		}
		else
			std::cout << "Error : impossible to find result." << std::endl;
	}
	std::cout << result << std::endl;		
}

RPN::RPN(const RPN &copy)
{
	this->_stack = copy._stack;
	*this = copy;
}

RPN::~RPN()
{
}

RPN	&RPN::operator=(const RPN &op)
{
	if (this != &op)
		this->_stack = op._stack;
	return *this;
}