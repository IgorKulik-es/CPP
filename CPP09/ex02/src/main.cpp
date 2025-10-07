/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/07 20:49:02 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int main(int argc, char** argv)
{
	//trying to sort with vector
	PmergeMe<std::vector<int>, std::vector<int>::iterator>	sorter_vector;
	time_t	timer;
	timeval	time_v;

	if (sorter_vector.scan_numbers(argc, argv) == NULL)
		std::cerr << "Error" << std::endl;
	std::cout << "Before:\t";
	sorter_vector.print_numbers();
	gettimeofday(&time_v, NULL);
	timer = time_v.tv_sec * MILLISEC + time_v.tv_usec;
	sorter_vector.sort();
	gettimeofday(&time_v, NULL);
	timer = time_v.tv_sec * MILLISEC + time_v.tv_usec - timer;
	std::cout << "After:\t";
	sorter_vector.print_numbers();
	std::cout << "Time to process a range of " << sorter_vector.getSize() << " elements with std::vector: " << timer << " us.\n";
	std::cout << "Number of comparisons: " << PmergeMe<std::vector<int>, std::vector<int>::iterator>::getNumComps() << std::endl;

	//trying the same sort with list
/* 	PmergeMe<std::list<int>, std::list<int>::iterator>	sorter_list;

	sorter_list.scan_numbers(argc, argv);
	gettimeofday(&time_v, NULL);
	timer = time_v.tv_sec * MILLISEC + time_v.tv_usec;
	sorter_list.sort();
	gettimeofday(&time_v, NULL);
	timer = time_v.tv_sec * MILLISEC + time_v.tv_usec - timer;
	std::cout << "Time to process a range of " << sorter_list.getSize() << " elements with std::list: " << timer << " us.\n";
	std::cout << "Number of comparisons: " << PmergeMe<std::list<int>, std::list<int>::iterator>::getNumComps() << std::endl;
	sorter_list.print_numbers(); */
}
