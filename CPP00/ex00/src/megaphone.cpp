/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:58:49 by ikulik            #+#    #+#             */
/*   Updated: 2025/07/29 15:40:18 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

int	main(int argc, char **argv)
{
	std::string	str;

	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (int j = 0; str[j]; j++)
			str[j] = toupper(str[j]);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
