/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:04:51 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/08 12:59:32 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string	darkest_secret;
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
	public:
		void		CopyContact(Contact *src);
		void		SetName( std::string name );
		void		SetLastName( std::string name );
		void		SetNick( std::string name );
		void		SetPhone( std::string name );
		void		SetDarkestSecret( std::string secret );
		std::string	GetDarkestSecret( void );
		std::string	GetName( void );
		std::string	GetLastName( void );
		std::string	GetNick( void );
		std::string	GetPhone( void );
		};

#endif
