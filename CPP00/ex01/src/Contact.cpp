/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:37:08 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/08 13:00:14 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

void	Contact::SetName( std::string name )
{
	this->name = name;
}

void	Contact::SetLastName( std::string last_name )
{
	this->last_name = last_name;
}

void	Contact::SetPhone( std::string phone )
{
	this->phone_number = phone;
}

void	Contact::SetNick( std::string nick )
{
	this->nickname = nick;
}

void	Contact::SetDarkestSecret( std::string secret )
{
	darkest_secret = secret;
}

std::string	Contact::GetDarkestSecret( void )
{
	return darkest_secret;
}

std::string	Contact::GetName( void )
{
	return name;
}

std::string	Contact::GetLastName( void )
{
	return last_name;
}

std::string	Contact::GetNick( void )
{
	return nickname;
}

std::string	Contact::GetPhone( void )
{
	return phone_number;
}

void	Contact::CopyContact( Contact *src )
{
	this->name = src->GetName();
	this->last_name = src->last_name;
	this->nickname = src->nickname;
	this->phone_number = src->phone_number;
	this->darkest_secret = src->GetDarkestSecret();
}
