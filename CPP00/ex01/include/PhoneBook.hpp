/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:04:51 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/01 13:35:58 by ikulik           ###   ########.fr       */
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
	public:
		int			num_conts;
		void		AddContact(Contact *new_cont);
		Contact*	GetContact(int index);
		void		PrintContact(int index);
		PhoneBook();
};

void	PrintHistoryLine(Contact *cont, int index);
void	ScanContactData(PhoneBook *book);

#endif
