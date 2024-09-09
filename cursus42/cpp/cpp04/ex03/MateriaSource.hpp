/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:50:13 by greg              #+#    #+#             */
/*   Updated: 2024/09/05 17:46:35 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include <iostream>

class IMateriaSource
{
public:
virtual ~IMateriaSource();
virtual void learnMateria(AMateria *materia) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
virtual void	getmaterias() const = 0;
};


class MateriaSource : public IMateriaSource
{

public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	virtual ~MateriaSource();

	MateriaSource	&operator=(const MateriaSource &op);
	virtual void	getmaterias() const;

	virtual void learnMateria(AMateria *materia);
	virtual AMateria	*createMateria(std::string const &type);
private:

	AMateria *materias[4];
	int size;
};





#endif