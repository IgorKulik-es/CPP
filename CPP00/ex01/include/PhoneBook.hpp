/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:04:51 by ikulik            #+#    #+#             */
/*   Updated: 2025/07/31 17:23:13 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "iostream"
# include <array>
# include "Contact.hpp"
# include "cctype"
# define CONT_MAX 8
# define WIDTH 10

class PhoneBook
{
	private:
		std::array <Contact, 8>	contacts;
	public:
		int			num_conts;
		void		AddContact(Contact new_cont);
		Contact*	GetContact(int	index);
};

void	PrintHistoryLine(Contact *cont, int index);

#endif
