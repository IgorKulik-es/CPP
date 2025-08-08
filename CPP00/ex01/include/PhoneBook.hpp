/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:04:51 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/08 12:54:47 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# define CONT_MAX 8
# define WIDTH 10

class PhoneBook
{
	private:
		Contact		contacts[CONT_MAX];
		int			num_conts;
	public:
		void		AddContact(Contact *new_cont);
		Contact*	GetContact(int index);
		int			GetNbContacts();
		void		PrintContact(int index);
		PhoneBook();
};

void	PrintHistoryLine(Contact *cont, int index);
void	ScanContactData(PhoneBook *book);

#endif
