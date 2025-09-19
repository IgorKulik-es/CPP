/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:54:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/19 14:14:01 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
	int	arr[5] = {0, 1, 2, 3, 4};
	int	lenght = 5;

	::iter(arr, 5, &print_element);
	::iter(arr, lenght, &increment_element);
	std::cout << std::endl;
	::iter(arr, lenght, &print_element);
	return 0;
}
