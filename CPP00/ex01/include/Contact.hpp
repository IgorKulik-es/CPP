/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:04:51 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/01 13:18:54 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string	darkest_secret;
	public:
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		void		SetDarkestSecret(std::string);
		std::string	GetDarkestSecret(void);
		void		CopyContact(Contact *src);
};

#endif
