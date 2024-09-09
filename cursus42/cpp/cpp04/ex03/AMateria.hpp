/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:54:10 by greg              #+#    #+#             */
/*   Updated: 2024/09/05 18:29:07 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &copy);
	virtual ~AMateria();

	AMateria &operator=(const AMateria &op);
	std::string const &getType() const;

	virtual AMateria* clone() const = 0;
	
	virtual void use(int index, ICharacter& target);

protected:
	std::string type;
};

#endif