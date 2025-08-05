/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 09:39:38 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/03 09:39:38 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}
Fixed::Fixed( const Fixed& copy )
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = copy.getRawBits();
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

const int	Fixed::b_point = 8;

int		Fixed::getRawBits( void ) const
{
	return this->value;
}
void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}
void	Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = copy.getRawBits();
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	value = nb << b_point;
}

Fixed::Fixed ( const float nb)
{
	value = roundf(nb * (1 << b_point));
}

float	Fixed::toFloat( void ) const
{
	float	tmp;

	tmp = value >> b_point;
	tmp += (float)(value & ((1 << b_point) - 1)) / (1 << b_point);
	return tmp;
}

int	Fixed::toInt ( void ) const
{
	return this->value >> b_point;
}

std::ostream&	operator<<( std::ostream &outstream, const Fixed& obj)
{
	float	tmp;

	tmp = obj.toFloat();
	outstream << tmp;
	return outstream;
}