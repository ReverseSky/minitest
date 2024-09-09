/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:00:41 by greg              #+#    #+#             */
/*   Updated: 2024/09/05 17:44:53 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define	ICHARACTER_HPP

#include <iostream>
#include <string>
#include "Ice.hpp"
#include "Cure.hpp"

class ICharacter
{
public:
	virtual ~ICharacter();

	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int index) = 0;
	virtual void use(int index, ICharacter& target) = 0;
};

class Character : public ICharacter 
{
	public:
		Character(std::string name);
		Character(Character const &copy);
		virtual	~Character();

		Character					&operator=(Character const &op);
		virtual std::string const	&getName() const;

		virtual void				equip(AMateria *m);
		virtual void				unequip(int index);
		virtual void				use(int index, ICharacter &target);
	private:
		int							size;
		std::string					name;
		AMateria					*inventory[4];
};



#endif