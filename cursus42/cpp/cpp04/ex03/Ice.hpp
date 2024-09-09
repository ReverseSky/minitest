/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:29:42 by greg              #+#    #+#             */
/*   Updated: 2024/09/05 17:36:45 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &copy);
	~Ice();

	Ice	&operator=(const Ice &op);
	virtual AMateria	*clone() const;
	virtual void	use(ICharacter &target);

};




#endif