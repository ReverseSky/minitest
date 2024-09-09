/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:54:27 by greg              #+#    #+#             */
/*   Updated: 2024/09/04 04:51:56 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "AAnimal.hpp"

class Brain
{

public:
	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain &operator=(const Brain &op);
	void addIdea(std::string idea);
	const std::string	&getIdea(unsigned int index) const;

private:
	std::string ideas[100];
	unsigned int	size;

};



#endif