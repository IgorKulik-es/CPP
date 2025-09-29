/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/29 14:51:55 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.hpp>

int main()
{
	std::cout << "Trying code with MutantStack: " << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Current size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	{
		std::cout << "Trying the same code with List: " << std::endl;
		std::list<int> lstack;

		lstack.push_back(5);
		lstack.push_back(17);
		std::cout << "Top element: " << lstack.back() << std::endl;
		lstack.pop_back();
		std::cout << "Current size: " << lstack.size() << std::endl;
		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		lstack.push_back(0);
		std::list<int>::iterator	it = lstack.begin();
		std::list<int>::iterator	ite = lstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	std::cout << "Testing copy constructor:" << std::endl;
	MutantStack<int>	copy_stack(mstack);
	it = copy_stack.begin();
	ite = copy_stack.end();
	for( ; it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::stack<int> s(mstack);
	return 0;
}
