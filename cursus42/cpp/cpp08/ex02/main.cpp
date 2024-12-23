/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 10:38:11 by greg              #+#    #+#             */
/*   Updated: 2024/12/22 10:59:12 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"

// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }

int main()
{
	std::list<int> mstack;
	
	mstack.push_front(5);
	mstack.push_front(7);

	std::cout << "number at the top of the stack : " << mstack.front() << std::endl;

	std::cout<< "delete top number" << std::endl;

	mstack.pop_front();

	std::cout << "number at the top of the stack : " << mstack.front() << std::endl;

	mstack.push_front(3);
	mstack.push_front(5);
	mstack.push_front(737);
	mstack.push_back(0);

	std::cout <<  "stacki size : " <<  mstack.size() << "." << std::endl;

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		ite--;
		std::cout << *ite << std::endl;
	}

	std::cout << "number at the top of the stack : " << mstack.front() << std::endl;

	std::list<int> s(mstack);
	return 0;
}