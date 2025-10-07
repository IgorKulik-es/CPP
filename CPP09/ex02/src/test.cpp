/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:41:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/07 18:17:38 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <PmergeMe.hpp>

# include <list>
# include <deque>
# include <vector>
# include <iostream>
# include <exception>
# include <cstdlib>
# include <sys/time.h>

int main(int argc, char** argv)
{
	//trying to sort with deque
	//std::cout << "Time to process a range of " << sorter_vector.getSize() << " elements with std::vector:\t" << timer << ".\n";

/* 	PmergeMe<std::list<int>, std::list<int>::iterator>	sorter_list;
	std::list<int>::iterator	iter;
	std::list<int>	tail;

	if (sorter_list.scan_numbers(argc, argv) == NULL)
		std::cerr << "Error" << std::endl;
	iter = sorter_list.getBase().begin();
	std::advance(iter, 1);
	sorter_list.print_numbers();
	sorter_list.move_pair(sorter_list.getBase(), sorter_list.getBase().begin(), sorter_list.getBase(), iter, 1);
	sorter_list.print_numbers(); */
/* 	sorter_deque.print_numbers();
	sorter_deque.sort();
	sorter_deque.print_numbers();


	{
	PmergeMe<std::list<int>, std::list<int>::iterator>	sorter_list;
	std::list<int>	tail;

	if (sorter_list.scan_numbers(argc, argv) == NULL)
		std::cerr << "Error" << std::endl;
	sorter_list.print_numbers();
	sorter_list.sort();
	sorter_list.print_numbers();
	} */

	std::vector<int>	test = {1, 2, 3};
	std::vector<int>::iterator	iter = test.begin();

	std::cout << *iter << " ";
	std::advance(iter, 1);
	std::cout << *iter << " ";
	std::advance(iter, 1);
	std::cout << *iter << " ";
	std::advance(iter, 2);
	std::cout << *iter << " ";
	return (0);
}
