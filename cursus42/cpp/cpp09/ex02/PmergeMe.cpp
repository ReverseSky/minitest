/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:42 by greg              #+#    #+#             */
/*   Updated: 2025/01/08 18:13:11 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> & input, int size) : _vector(input), _deque(input.begin(), input.end()), _size(size)
{
	this->_vecSort();
	this->_DequeSort();
}

PmergeMe::PmergeMe(PmergeMe const &src) : _size(src._size)
{
	this->_vector = src._vector;
	this->_deque = src._deque;
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &	PmergeMe::operator=(PmergeMe const &rSym)
{
	if (this != &rSym)
	{
		this->_vector = rSym._vector;
		this->_deque = rSym._deque;
	}
	return *this;
}

void PmergeMe::_vecSort()
{
	clock_t start = clock();

	// Vérification des tailles
	if (this->_vector.size() <= 1)
	{
		std::cout << "After: ";
		for (size_t i = 0; i < this->_vector.size(); i++)
			std::cout << " " << this->_vector[i];
		std::cout << std::endl;

		clock_t end = clock();
		double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << this->_size
				<< " elements with std::vector<int> : " << duration << " us" << std::endl;
		return;
	}

	// Division en deux sous-vecteurs
	size_t const half_size = this->_vector.size() / 2;
	std::vector<int> split_lo(this->_vector.begin(), this->_vector.begin() + half_size);
	std::vector<int> split_hi(this->_vector.begin() + half_size, this->_vector.end());

	// Tri récursif des deux parties
	std::sort(split_lo.begin(), split_lo.end());
	std::sort(split_hi.begin(), split_hi.end());

	// Fusion des deux parties triées
	std::vector<int> merged;
	size_t i = 0, j = 0;
	while (i < split_lo.size() && j < split_hi.size())
	{
		if (split_lo[i] < split_hi[j])
		{
			merged.push_back(split_lo[i]);
			i++;
		} else
		{
			merged.push_back(split_hi[j]);
			j++;
		}
	}

	// Ajout des éléments restants
	while (i < split_lo.size())
	{
		merged.push_back(split_lo[i]);
		i++;
	}
	while (j < split_hi.size())
	{
		merged.push_back(split_hi[j]);
		j++;
	}

	// Affichage du vecteur trié
	std::cout << "After: ";
	for (size_t k = 0; k < merged.size(); k++)
		std::cout << " " << merged[k];
	std::cout << std::endl;

	// Calcul du temps d'exécution
	clock_t end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << this->_size
			  << " elements with std::vector<int> : " << duration << " us" << std::endl;
}

void PmergeMe::_DequeSort()
{
	clock_t start = clock();

	if (this->_deque.size() <= 1) {
		std::cout << "Deque is already sorted or empty." << std::endl;
		return;
	}

	// Diviser le deque en deux moitiés
	size_t const half_size = this->_deque.size() / 2;
	std::deque<int> split_lo;
	std::deque<int> split_hi;

	std::deque<int>::iterator it = this->_deque.begin();
	for (size_t i = 0; i < half_size; ++i, ++it) {
		split_lo.push_back(*it);
	}
	for (; it != this->_deque.end(); ++it) {
		split_hi.push_back(*it);
	}

	// Trier chaque moitié individuellement
	std::sort(split_lo.begin(), split_lo.end());
	std::sort(split_hi.begin(), split_hi.end());

	// Fusionner les deux moitiés triées
	std::deque<int> merged;
	std::deque<int>::iterator it_lo = split_lo.begin();
	std::deque<int>::iterator it_hi = split_hi.begin();

	while (it_lo != split_lo.end() && it_hi != split_hi.end()) {
		if (*it_lo <= *it_hi) {
			merged.push_back(*it_lo);
			++it_lo;
		} else {
			merged.push_back(*it_hi);
			++it_hi;
		}
	}

	// Ajouter les éléments restants
	while (it_lo != split_lo.end()) {
		merged.push_back(*it_lo);
		++it_lo;
	}
	while (it_hi != split_hi.end()) {
		merged.push_back(*it_hi);
		++it_hi;
	}

	// Remplacer le deque d'origine par le résultat fusionné
	this->_deque.swap(merged);

	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << this->_size
			<< " elements with std::deque<int>: " << duration << " us" << std::endl;
}
