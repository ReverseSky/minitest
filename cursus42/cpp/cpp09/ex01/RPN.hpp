/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:20:01 by greg              #+#    #+#             */
/*   Updated: 2024/12/27 17:36:20 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

class RPN
{

public:
	RPN(char *input);
	RPN(const RPN &copy);
	~RPN();

	RPN	&operator=(const RPN &op);
private:
	std::stack<int>	_stack;
};



#endif