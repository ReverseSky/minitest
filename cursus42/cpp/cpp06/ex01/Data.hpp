/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:07:02 by greg              #+#    #+#             */
/*   Updated: 2024/12/19 17:15:17 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{

public:
	Data();
	Data(const Data &copy);
	~Data();

	Data	&operator=(const Data &op);
	int		getSize() const;

private:
	int	_size;
};

std::ostream	&operator<<(std::ostream & out, Data const &op);


#endif