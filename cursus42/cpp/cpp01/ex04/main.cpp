/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:38:54 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/22 12:05:08 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "error comment must be : ./replace filename <string1> <string2>" << std::endl;
	}
	if (argc == 4)
	{
		std::string	filename(argv[1]);
		std::string	s1 = argv[2];
		std::string	s2 = argv[3];
		int	c;

		std::ifstream	ifs(filename.c_str());
		c = ifs.peek();
		if (c == EOF)
			std::cout << "error file is empty" << std::endl;
		else
		{
			std::ofstream ofs(filename.append(".replace").data());
			while (ifs.good() && ofs.good())
			{
				std::string line;
				std::size_t found;
				std::getline(ifs, line);
				found = line.find(s1, 0);
				while (found != std::string::npos)
				{
					line.erase(found, s1.length());
					line.insert(found, s2);
					found = line.find(s1, found);
				}
				ofs << line;
				if (ifs.eof())
					break;
				ofs << std::endl;
			}
			ifs.close();
			ofs.close();
		}
	}
	else
			std::cout << "Error can not open file " << std::endl;
}

