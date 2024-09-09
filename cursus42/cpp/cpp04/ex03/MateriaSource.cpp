/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:50:10 by greg              #+#    #+#             */
/*   Updated: 2024/09/05 18:25:42 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource() : size(0) {
	std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	std::cout << "MateriaSource copy constructor called." << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource default destructor called." << std::endl;
	int index = -1; 
	while (++index < this->size)
		delete this->materias[index];
}

IMateriaSource::~IMateriaSource() {
	std::cout << "IMateriaSource interface default destructor called." << std::endl;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const &rSym) {
	if (this != &rSym) {
		this->size = rSym.size;
		int index = -1; while (++index < 4)
			this->materias[index] = rSym.materias[index];
	}
	return *this;
}

void	MateriaSource::getmaterias() const {
	std::cout << "MateriaSource's memory contain :" << std::endl;
	int	index = -1; while (++index < size)
		std::cout << "\t[" << index << "] " << this->materias[index]->getType() << std::endl;
}

void		MateriaSource::learnMateria(AMateria *materia) {
	if (this->size == 4) {
		std::cout << "MateriaSource is full of memory. Can't add a new AMateria model." << std::endl; return;
	}
	this->materias[size] = materia;
	this->size++;
}

AMateria *	MateriaSource::createMateria(std::string const &type) {
	int	index = -1; while (++index < size) {
		if (this->materias[index]->getType() == type)
			return this->materias[index];
	}
	std::cout << "This MateriaSource don't have the type : " << type << " in memory." << std::endl;
	return NULL;
}