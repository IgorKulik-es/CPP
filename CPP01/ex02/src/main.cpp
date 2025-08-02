/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:48:17 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/02 12:48:17 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void )
{
	std::string		stringORG = "HI THIS IS BRAIN";
	std::string*	stringPTR = &stringORG;
	std::string&	stringREF = stringORG;

	std::cout << "Original memory address:\t" << &stringORG << std::endl;
	std::cout << "Pointer memory address:\t\t" << stringPTR << std::endl;
	std::cout << "Reference memory address:\t" << &stringREF << std::endl;

	std::cout << "Value of original:\t" << stringORG << std::endl;
	std::cout << "Value of pointer:\t" << *stringPTR << std::endl;
	std::cout << "Value of reference:\t" << stringREF << std::endl;

	return (0);
}