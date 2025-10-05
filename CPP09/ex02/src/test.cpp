/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:41:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/03 13:41:26 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int main(int argc, char** argv)
{
	//trying to sort with deque
	PmergeMe<std::vector<int>, std::vector<int>::iterator>	sorter_vector(M_DEQUE);
	std::vector<int>	tail;

	if (sorter_vector.scan_numbers(argc, argv) == NULL)
		std::cerr << "Error" << std::endl;
	sorter_vector.print_numbers();
	sorter_vector.sort();
	sorter_vector.print_numbers();
	//std::cout << "Time to process a range of " << sorter_deque.getSize() << " elements with std::deque:\t" << timer << ".\n";
}