/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:54:10 by greg              #+#    #+#             */
/*   Updated: 2024/09/11 18:46:45 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria {
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		virtual ~AMateria();

		AMateria &	operator=(AMateria const &rSym);
		std::string const &	getType() const;

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);

protected:
	std::string type;
};

#endif