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

#include "../include/PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;
	Contact		cont;
	PhoneBook	book;
	std::string	temp;

	std::cout << "Enter command: ";
	std::cin >> cmd;
	while (cmd.compare("EXIT") != 0)
	{
		if (cmd.compare("ADD") == 0)
		{
			std::cout << "Enter contac's name: ";
			std::cin >> cont.name;
			std::cout << std::endl << "Enter contact's last name: ";
			std::cin >> cont.last_name;
			std::cout << std::endl << "Enter contact's phone number: ";
			std::cin >> cont.phone_number;
			std::cout << std::endl << "Enter contact's darkest secret: ";
			std::cin >> temp;
			cont.SetDarkestSecret(temp);
			std::cout << std::endl;
			book.AddContact(cont);
		}
		if (cmd.compare("SEARCH") == 0)
		{
			for (int i; i < book.num_conts; i++)
				PrintHistoryLine(book.GetContact(i), i);
		}
		if (cmd.compare("EXIT") != 0)
			std::cout << "Input error";
		std::cin >> cmd;
	}
}
