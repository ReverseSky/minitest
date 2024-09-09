/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:48:36 by greg              #+#    #+#             */
/*   Updated: 2024/09/05 17:20:04 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "Character.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &copy);
	~Cure();

	Cure	&operator=(const Cure &op);
	
	virtual AMateria	*clone() const;
	virtual void	use(ICharacter &target);
private:
	std::string type;

};




#endif