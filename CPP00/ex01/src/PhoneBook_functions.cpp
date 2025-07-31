/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_functions.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:58:49 by ikulik            #+#    #+#             */
/*   Updated: 2025/07/31 17:22:41 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

void	PhoneBook::AddContact(Contact new_cont)
{
	if (num_conts < CONT_MAX)
	{
		contacts[num_conts] = new_cont;
		num_conts++;
	}
	else
	{
		for (int i = 0; i < CONT_MAX - 1; i++)
			contacts[i] = contacts[i + 1];
		contacts[CONT_MAX - 1] = new_cont;
	}
};

Contact*	PhoneBook::GetContact(int index)
{
	return &(contacts[index]);
}

void	PrintOneData(std::string str)
{
	int	len;

	len = str.length();
	if (len >= WIDTH)
		std::cout << str.substr(WIDTH - 1) << ".";
	else
	{
		std::cout << std::string(WIDTH - len, ' ');
		std::cout << str;
	}
}

void	PrintHistoryLine(Contact *cont, int index)
{
	std::cout << index << " |";
	PrintOneData(cont->name);
	std::cout << "|";
	PrintOneData(cont->last_name);
	std::cout << "|";
	PrintOneData(cont->nickname);
	std::cout << std::endl;
}
