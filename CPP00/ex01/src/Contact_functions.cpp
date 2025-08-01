/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_functions.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:37:08 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/01 13:21:53 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

void	Contact::SetDarkestSecret(std::string secret)
{
	darkest_secret = secret;
}

std::string	Contact::GetDarkestSecret(void)
{
	return darkest_secret;
}

void	Contact::CopyContact(Contact *src)
{
	name = src->name;
	last_name = src->last_name;
	nickname = src->nickname;
	phone_number = src->phone_number;
	darkest_secret = src->GetDarkestSecret();
}
