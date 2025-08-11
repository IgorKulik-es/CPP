/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 09:39:38 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/11 16:42:12 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}
Fixed::Fixed( const Fixed& copy )
{
	this->value = copy.getRawBits();
}
Fixed::~Fixed()
{
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
	this->value = copy.getRawBits();
}

Fixed::Fixed(const int nb)
{
	value = nb << b_point;
}

Fixed::Fixed ( const float nb)
{
	value = roundf(nb * (1 << b_point));
}

float	Fixed::toFloat( void ) const
{
	float	tmp;

	tmp = (float)value / (1 << b_point);
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

bool	operator>(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits());
}

bool	operator<(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() < b.getRawBits());
}

bool	operator==(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() == b.getRawBits());
}

bool	operator!=(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() != b.getRawBits());
}

Fixed	operator+(const Fixed& a, const Fixed& b)
{
	Fixed	tmp;

	tmp.setRawBits(a.getRawBits() + b.getRawBits());
	return (tmp);
}

Fixed	operator-(const Fixed& a, const Fixed& b)
{
	Fixed	tmp;

	tmp.setRawBits(a.getRawBits() - b.getRawBits());
	return (tmp);
}

int		Fixed::getBinaryPoint( void ) const
{
	return this->b_point;
}

Fixed	operator*(const Fixed& a, const Fixed& b)
{
	Fixed	tmp;

	tmp.setRawBits((a.getRawBits() * b.getRawBits()) >> a.getBinaryPoint());
	return (tmp);
}

Fixed	operator/(const Fixed& a, const Fixed& b)
{
	Fixed	tmp;

	tmp.setRawBits((a.getRawBits() / b.getRawBits()) << a.getBinaryPoint());
	return (tmp);
}

Fixed	Fixed::operator++( void )
{
	Fixed	old;

	old = *this;
	(this->value)++;
	return (old);
}

Fixed&	Fixed::operator++( int )
{
	++(this->value);
	return (*this);
}

Fixed	Fixed::operator--( void )
{
	Fixed	old;

	old = *this;
	(this->value)--;
	return (old);
}

Fixed&	Fixed::operator--( int )
{
	--(this->value);
	return (*this);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}
