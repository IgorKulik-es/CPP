/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:56:23 by ikulik            #+#    #+#             */
/*   Updated: 2025/07/31 17:27:31 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	book;

	std::cout << "Enter command: ";
	std::cin >> cmd;
	while (cmd.compare("EXIT") != 0)
	{
		if (cmd.compare("ADD") == 0)
			ScanContactData(&book);
		else if (cmd.compare("SEARCH") == 0)
			SearchContact(&book);
		else if (cmd.compare("EXIT") != 0)
			std::cerr << "Input error" << std::endl;
		std::cout << "Enter command: ";
		std::cin >> cmd;
	}
}
