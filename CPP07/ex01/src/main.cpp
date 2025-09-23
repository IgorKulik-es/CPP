/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:54:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/23 19:26:20 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
	int	arr[5] = {0, 1, 2, 3, 4};
	const int arr_const[3] = {-42, 10, 0};
	const int	lenght = 5;

	std::cout << "Printing and changing non-const array:" << std::endl;
	iter(arr, 5, &print_element);
	iter(arr, lenght, &increment_element);
	std::cout << std::endl;
	iter(arr, lenght, &print_element);
	std::cout << std::endl;
	std::cout << "Printing const array:" << std::endl;
	iter(arr_const, 3, &print_element);
	std::cout << std::endl;
	return 0;
}
