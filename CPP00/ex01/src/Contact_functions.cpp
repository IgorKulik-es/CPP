/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_functions.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:37:08 by ikulik            #+#    #+#             */
/*   Updated: 2025/07/31 17:09:35 by ikulik           ###   ########.fr       */
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
