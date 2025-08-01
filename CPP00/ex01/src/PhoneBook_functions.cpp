/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_functions.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:58:49 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/01 13:38:55 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

PhoneBook::PhoneBook()
{
	num_conts = 0;
}


void	PhoneBook::AddContact(Contact *new_cont)
{
	if (num_conts < CONT_MAX)
	{
		contacts[num_conts].CopyContact(new_cont);
		num_conts++;
	}
	else
	{
		for (int i = 0; i < CONT_MAX - 1; i++)
			contacts[i] = contacts[i + 1];
		contacts[CONT_MAX - 1].CopyContact(new_cont);
	}
};

Contact*	PhoneBook::GetContact(int index)
{
	return &(contacts[index]);
}

void	PhoneBook::PrintContact(int index)
{
	std::cout << "Name:\t\t" << contacts[index].name << std::endl;
	std::cout << "Last name:\t" << contacts[index].last_name << std::endl;
	std::cout << "Nickname:\t" << contacts[index].nickname << std::endl;
	std::cout << "Phone number:\t" << contacts[index].phone_number << std::endl;
	std::cout << "Darkest Secret:\t" << contacts[index].GetDarkestSecret() << std::endl;
}

void	PrintOneItem(std::string str)
{
	if (str.length() >= WIDTH)
		std::cout << str.substr(0, WIDTH - 1) << ".";
	else
		std::cout << std::setfill(' ') << std::setw(WIDTH) << str;
}

void	PrintHistoryLine(Contact *cont, int index)
{
	std::cout << index << " |";
	PrintOneItem(cont->name);
	std::cout << "|";
	PrintOneItem(cont->last_name);
	std::cout << "|";
	PrintOneItem(cont->nickname);
	std::cout << std::endl;
}

void	ScanContactData(PhoneBook *book)
{
	Contact		cont;
	std::string	temp;

	std::cout << "Enter contact's name: ";
	std::cin >> cont.name;
	std::cout << "Enter contact's last name: ";
	std::cin >> cont.last_name;
	std::cout << "Enter contact's nickname: ";
	std::cin >> cont.nickname;
	std::cout << "Enter contact's phone number: ";
	std::cin >> cont.phone_number;
	std::cout << "Enter contact's darkest secret: ";
	std::cin >> temp;
	cont.SetDarkestSecret(temp);
	book->AddContact(&cont);
}

void	SearchContact(PhoneBook *book)
{
	int			index;
	std::string	input;

	if (book->num_conts == 0)
	{
		std::cerr << "Phonebook is empty!" << std::endl;
		return ;
	}
	for (int i = 0; i < book->num_conts; i++)
		PrintHistoryLine(book->GetContact(i), i);
	std::cout << "Input contact index: ";
	std::cin >> input;
	for (int j = 0; input[j]; j++)
	{
		if (std::isdigit(input[j]) == 0)
		{
			std::cerr << "Invalid index!" << std::endl;
			return ;
		}
	}
	index = std::atoi(input.c_str());
	std::cout << index << std::endl;
	if (index >= 0 && index < book->num_conts)
		book->PrintContact(index);
	else
		std::cerr << "Invalid index!" << std::endl;
}
