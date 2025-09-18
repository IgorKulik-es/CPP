/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:21:01 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/18 12:45:37 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter& copy):
{
	(void)copy;
}

void	ScalarConverter::operator=( const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter::~ScalarConverter(){};

void	ScalarConverter::convert(std::string number) const
{
	std::cout << "Conversion to char: " << static_cast<char>(number.c_str()[0]);
	std::cout <<
}
