/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/29 14:34:36 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

int main()
{
	Span sp = Span(5);
	Span small(3);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(9);
	std::cout << "Assigning to another array of sufficient size:" << std::endl;
	try
	{
		small = sp;
		std::cout << "Array copied successfully" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	sp.addNumber(17);
	sp.addNumber(11);

	std::cout << "Assigning an array of in sufficient size:" << std::endl;
	try
	{
		small = sp;
		std::cout << "Array copied successfully" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Shortest and longest span of sp: ";
	std::cout << sp.shortestSpan() << " ";
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "Shortest and longest span of small: ";
	std::cout << small.shortestSpan() << " ";
	std::cout << small.longestSpan() << std::endl;

	Span	big(10);

	std::cout << "Adding multiple numbers to new Span." << std::endl;
	try
	{
		big.addSpan(small.getContent().begin(), small.getContent().end());
		big.addSpan(sp.getContent().begin(), sp.getContent().end());
		std::cout << "Array copied successfully" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "New array content: ";
	for (size_t i = 0; i < big.getContent().size(); i++)
		std::cout << big.getContent()[i] << " ";
	std::cout << "\nTrying to add over maximum:" << std::endl;
	try
	{
		big.addSpan(sp.getContent().begin(), sp.getContent().end());
		std::cout << "Array copied successfully" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Trying to find span in too small an array:" << std::endl;
	Span	micro(1);

	micro.addNumber(3);
	try
	{
		std::cout << micro.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Shortest span failed with: " << e.what() << '\n';
	}

	std::cout << "Testing a span with 10000 members:" << std::endl;
	Span	large(100000);

	for (int i= 0; i < 100000; i++)
	{
		large.addNumber(i);
	}
	std::cout << "Longest span of large array: " << large.longestSpan() << std::endl;
	std::cout << "Shortest span of large array: " << large.shortestSpan() << std::endl;

	return 0;
}
