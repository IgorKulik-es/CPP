/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BtcData.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:59:03 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/08 13:07:53 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BtcData.hpp"

BtcData::BtcData()
{
	this->data.clear();
}

BtcData::BtcData( const BtcData& copy )
{
	*this = copy;
}

BtcData::~BtcData() {};

BtcData&	BtcData::operator=( const BtcData& copy )
{
	this->data = copy.getData();
	return (*this);
}

const std::map<std::string, float>&	BtcData::getData( void ) const
{
	return (this->data);
}

bool	BtcData::readCsv( const char* filename)
{
	std::ifstream		file;
	std::string			line;
	std::string			key;
	float				value;
	std::stringstream	line_stream;

	file.open(filename);
	if (file.is_open() == false)
	{
		std::cerr << "Error: couldn't open data file." << std::endl;
		return (EXIT_FAILURE);
	}
	std::getline(file, line);
	line.clear();
	while (std::getline(file, line))
	{
		line_stream.str(line);
		std::getline(line_stream, key, ',');
		line.clear();
		std::getline(line_stream, line);
		value = atof(line.c_str());
		this->data.insert(std::pair<std::string, float>(key, value));
		line_stream.clear();
	}
	return (EXIT_SUCCESS);
}

bool	BtcData::checkDateFormat( std::string& date )
{
	std::string				format;
	std::string::iterator	iter;
	int						num_date;
	std::stringstream		date_stream(date);

	while (isblank(date_stream.peek()))
		date_stream.get();
	std::getline(date_stream, format, '-');
	num_date = checkDateNumeric(format);
	if (num_date < MIN_YEAR)
		return (false);
	std::getline(date_stream, format, '-');
	num_date = checkDateNumeric(format);
	if (num_date < 0 || num_date > 12 || format.length() == 0)
		return (false);
	std::getline(date_stream, format, ' ');
	num_date = checkDateNumeric(format);
	if (num_date < 0 || num_date > 31 || format.length() == 0)
		return (false);
	date.resize(date.find_first_of(' '));
	format.clear();
	std::getline(date_stream, format);
	iter = format.begin();
	while ( iter != format.end() && isblank(*iter))
		iter++;
	if (iter != format.end())
		return (false);
	return (true);
}

int	BtcData::checkDateNumeric( const std::string& str )
{
	int	num_date;

	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
		if (isdigit(*it) == false)
			return (VALUE_FAILURE);
	num_date = atoi(str.c_str());
	return (num_date);
}

float	BtcData::checkValue( const std::string& number )
{
	std::string::const_iterator	iter;

	if (number.length() == 0)
		return (VALUE_FAILURE);
	iter = number.begin();
	while (isblank(*iter))
		iter++;
	if (iter == number.end() || *iter == '-')
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (OUT_OF_BOUND);
	}
	if (*iter == '+')
		iter++;
	if (*iter == '0')
		return(VALUE_FAILURE);
	while (isdigit(*iter))
		iter++;
	if (iter == number.end() || *iter == 13)
		return (checkWithinLimits(number));
	if (*iter != '.')
		return (VALUE_FAILURE);
	iter++;
	while (iter != number.end() && isdigit(*iter))
		iter++;
	while (iter != number.end() && (isblank(*iter) || *iter == 13))
		iter++;
	if (iter != number.end())
		return (VALUE_FAILURE);
	return (checkWithinLimits(number));
}

float	BtcData::checkWithinLimits( const std::string& number )
{
	float	num;

	num = atof(number.c_str());
	if (num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (OUT_OF_BOUND);
	}
	if (num > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (OUT_OF_BOUND);
	}
	return (num);
}

int	BtcData::printValues( const char* filename)
{
	std::ifstream		file;
	std::string			line;

	file.open(filename);
	if (file.is_open() == false)
	{
		std::cerr << "Error: couldn't open input file." << std::endl;
		return (EXIT_FAILURE);
	}
	std::getline(file, line);
	line.clear();
	while (std::getline(file, line))
	{
		this->printOneLine(line);
		line.clear();
	}
	return (EXIT_SUCCESS);
}

void	BtcData::printOneLine( const std::string& line )
{
	std::string			key;
	std::string			str_value;
	float				num_value;
	float				price;
	std::stringstream	line_stream;

	line_stream.str(line);
	std::getline(line_stream, key, '|');
	if (checkDateFormat(key) == false)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	std::getline(line_stream, str_value, '|');
	num_value = checkValue(str_value);
	if (num_value == VALUE_FAILURE)
		std::cerr << "Error: bad input => " << line << std::endl;
	if (num_value == VALUE_FAILURE || num_value == OUT_OF_BOUND)
		return ;
	str_value.clear();
	std::getline(line_stream, str_value);
	if (str_value.length() > 0)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	price = this->findClosestPrice(key);
	if (price == VALUE_FAILURE)
		return ;
	std::cout << key << " => " << num_value << " = " << (price * num_value) << std::endl;
}

float	BtcData::findClosestPrice( const std::string& date)
{
	std::map<std::string, float>::iterator	find;

	if (date < this->data.begin()->first)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return (VALUE_FAILURE);
	}
	find = this->data.upper_bound(date);
	find--;
	return (find->second);
}
