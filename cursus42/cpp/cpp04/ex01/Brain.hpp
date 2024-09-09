/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:54:27 by greg              #+#    #+#             */
/*   Updated: 2024/09/09 16:17:40 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{

public:
	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain &operator=(const Brain &op);

	std::string ideas[100];
private:
	unsigned int	size;
};



#endif