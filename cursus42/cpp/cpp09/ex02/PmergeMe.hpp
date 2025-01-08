/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:47 by greg              #+#    #+#             */
/*   Updated: 2025/01/08 18:04:01 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PMERGEME_HPP_
#define _PMERGEME_HPP_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <deque>

typedef std::string str;

class PmergeMe {
	public:
		PmergeMe(std::vector<int> & input, int size);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe &	operator=(PmergeMe const &rSym);
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		const int			_size;

		void	_vecSort();
		void	_DequeSort();
};

#endif
