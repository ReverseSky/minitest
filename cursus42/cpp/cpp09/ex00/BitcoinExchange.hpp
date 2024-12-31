/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:28:04 by greg              #+#    #+#             */
/*   Updated: 2024/12/24 03:03:12 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BITCOINEXCHANGE_HPP_
#define _BITCOINEXCHANGE_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

template <typename T>
std::string itos(T nb) 
{
	std::ostringstream	ss;
	ss << nb;
	return ss.str();
}

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream & file, char ** av);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange &	operator=(BitcoinExchange const &rSym);

		void		printMap() const;

	private:
		std::map<std::string, float>	_map;
		int						_inputSize;
		int *					_input;
		std::string const				_inputPath;

		int		_getInputSize(std::ifstream & file) const;
		void	_parseData(std::ifstream & file);
		void	_parseInput(std::ifstream & file);
		bool	_checkDate(std::string line);
		bool	_checkPositive(std::string line);
		bool	_checkTooLarge(std::string line);
		void	_output(std::ifstream & file);
		void	_nearestDate(std::string & key);
};

std::string 		trim(const std::string & str);

#endif