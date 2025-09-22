/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:54:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/22 13:20:43 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main()
{
	Bureaucrat	dave("Dave", 2);

	std::cout << "Instantiated: " << dave << std::endl;
	dave.IncrementGrade();

	std::cout << "Incremening beyond the highest grade:\t";
	try
	{
		dave.IncrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Instantiating below the lowest grade:\t";
	try
	{
		Bureaucrat	too_low("Hugh", 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Decremening below the lowest grade:\t";
	Bureaucrat	lowest("Fry", 150);
	try
	{
		lowest.DecrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
