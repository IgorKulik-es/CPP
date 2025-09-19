/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/19 15:50:37 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

#define MAX_VAL 750
int main(int, char **)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		std::cout << "Instatiating two deep copies of an array" << std::endl;
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << "First elements before change:\t" << tmp[0] << " " << test[0] << " " << numbers[0] << std::endl;
		(tmp[0])++;
		(test[0])--;
		std::cout << "First elements after change:\t" << tmp[0] << " " << test[0] << " " << numbers[0] << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "The two arrays \"numbers\" and \"mirror\" coinside" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //
	return 0;
}
