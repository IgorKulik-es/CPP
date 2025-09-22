/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:21:01 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/22 16:48:23 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter& copy)
{
	(void)copy;
}

void	ScalarConverter::operator=( const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter::~ScalarConverter(){};

char	ScalarConverter::get_type( std::string number )
{
	std::string::iterator	iter;
	std::string::iterator	num_start;

	if (number.compare("-inf") == 0 || number.compare("+inf") == 0|| number.compare("nan") == 0)
		return (T_DOUBLE);
	if (number.compare("-inff") == 0 || number.compare("+inff") == 0|| number.compare("nanf") == 0)
		return (T_FLOAT);
	iter = number.begin();
	num_start = iter;
	if (*iter == '\'' && number.length() == 3 && number[2] == '\'')
		return (T_CHAR);
	if (*num_start == '-')
	{
		iter++;
		num_start++;
	}
	while (isdigit(*iter))
		iter++;
	if (iter == number.end())
		return (T_INT);
	if (*iter != '.')
		return (0);
	do
		iter++;
	while (isdigit(*iter));
	if (iter == number.end())
		return (T_DOUBLE);
	if (*iter == 'f')
		return (T_FLOAT);
	return (T_NOTFOUND);
}

void	ScalarConverter::print_type( std::string number, char type_name )
{
	switch (type_name)
	{
	case 'c':
		print_char(number[1]);
		break ;
	case 'i':
		print_int(atoi(number.c_str()));
		break ;
	case 'f':
		print_float(atof(number.c_str()));
		break ;
	case 'd':
		print_double(atof(number.c_str()));
		break ;
	default:
		break;
	}
}

void	ScalarConverter::convert( std::string number )
{
	char	num_type;

	num_type = get_type(number);
	if (num_type)
		print_type(number, num_type);
	else
		std::cerr << "Type unrecognized" << std::endl;
}

void	ScalarConverter::print_char( char c )
{
	std::cout << "Identified type: char" << std::endl;
	std::cout << "char:\t'";
	correct_char(c);
	std::cout << "int:\t" << static_cast<int>(c) << std::endl;
	std::cout << "float:\t" << static_cast<float>(c) << std::endl;
	std::cout << "double:\t" << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::print_int( int i )
{
	std::cout << "Identified type: int" << std::endl;
	std::cout << "char:\t'";
	correct_char(static_cast<char>(i));
	std::cout << "int:\t" << i << std::endl;
	std::cout << "float:\t" << static_cast<float>(i) << std::endl;
	std::cout << "double:\t" << static_cast<double>(i) << std::endl;
}

void	ScalarConverter::print_float( float f )
{
	std::cerr << "Identified type: float" << std::endl;
	std::cout << "char:\t'";
	correct_char(static_cast<char>(f));
	std::cout << "int:\t";
	correct_int(f);
	std::cout << "float:\t" << f << std::endl;
	std::cout << "double:\t" << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::print_double( double d )
{
	std::cerr << "Identified type: double" << std::endl;
	std::cout << "char:\t";
	correct_char(static_cast<char>(d));
	std::cout << "int:\t";
	correct_int(d);
	std::cout << "float:\t" << static_cast<float>(d) << std::endl;
	std::cout << "double:\t" << d << std::endl;
}

void	ScalarConverter::correct_char(char c)
{
	if (isprint(c))
		std::cout  << "'" << c << "'" << std::endl;
	else
		std::cout << "imposible" << std::endl;
}

void	ScalarConverter::correct_int(double d)
{
	if (std::isnormal(d))
		std::cout << static_cast<int>(d) << std::endl;
	else
		std::cout << "imposible" << std::endl;
}
