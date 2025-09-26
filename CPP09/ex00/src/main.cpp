/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/23 19:15:09 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>

int main()
{
	std::vector<int>			arr_int;
	std::list<int>				lst_int;
	std::vector<int>::iterator	find_vector;
	std::list<int>::iterator	find_list;
	int							value = 2;

	arr_int.push_back(1);
	arr_int.push_back(2);
	arr_int.push_back(3);
	lst_int.push_back(-5);
	lst_int.push_back(4);
	lst_int.push_back(3);
	try
	{
		std::cout << "Looking for " << value << " in vector:" << std::endl;
		find_vector = easyfind(arr_int, value);
		std::cout << "Found value: " << *find_vector << " at: " << &(*find_vector) << std::endl;
	}
	catch(int err)
	{
		std::cerr << "No value found" << std::endl;
	}
	try
	{
		std::cout << "Looking for " << value << " in list:" << std::endl;
		find_list = easyfind(lst_int, value);
		std::cout << "Found value: " << *find_list << " at: " << &(*find_list) << std::endl;
	}
	catch(int err)
	{
		std::cerr << "No value found" << std::endl;
	}
	return 0;
}
