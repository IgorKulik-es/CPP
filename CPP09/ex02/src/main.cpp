/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/02 20:13:01 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int main(int argc, char** argv)
{
	//trying to sort with deque
	PmergeMe<std::deque<int>, std::deque<int>::iterator>	sorter_deque(M_DEQUE);
	time_t	timer;
	timeval	time_v;

	if (sorter_deque.scan_numbers(argc, argv) == NULL)
		std::cerr << "Error" << std::endl;
	sorter_deque.print_numbers();
	gettimeofday(&time_v, NULL);
	timer = time_v.tv_sec * MILLISEC + time_v.tv_usec;
	sorter_deque.sort();
	gettimeofday(&time_v, NULL);
	timer = time_v.tv_sec * MILLISEC + time_v.tv_usec - timer;
	sorter_deque.print_numbers();
	std::cout << "Time to process a range of " << sorter_deque.getSize() << " elements with std::deque:\t" << timer << ".\n";

	//trying the same sort with list
	PmergeMe<std::list<int>, std::list<int>::iterator>	sorter_list(M_LIST);

	sorter_list.scan_numbers(argc, argv);
	gettimeofday(&time_v, NULL);
	timer = time_v.tv_sec * MILLISEC + time_v.tv_usec;
	sorter_list.sort();
	gettimeofday(&time_v, NULL);
	timer = time_v.tv_sec * MILLISEC + time_v.tv_usec - timer;
	std::cout << "Time to process a range of " << sorter_list.getSize() << " elements with std::list:\t" << timer << ".\n";
	sorter_list.print_numbers();
}
