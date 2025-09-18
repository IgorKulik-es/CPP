/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:54:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/18 17:34:14 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main()
{
	std::cout << "Char literal: a" << std::endl;
	ScalarConverter::convert("'a'");
	std::cout << "Int literal: 98" << std::endl;
	ScalarConverter::convert("98");
	std::cout << "Float literal: +inff" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "Double literal: nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "Unrecoginzable literal: k" << std::endl;
	ScalarConverter::convert("k");
	std::cout << "Unrecoginzable literal: 13.2e" << std::endl;
	ScalarConverter::convert("13.2e");
	return (0);
}
