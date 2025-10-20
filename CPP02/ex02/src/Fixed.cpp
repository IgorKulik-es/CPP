/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 09:39:38 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/20 12:54:09 by ikulik           ###   ########.fr       */
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

bool	Fixed::operator>(const Fixed& b ) const
{
	return (this->getRawBits() > b.getRawBits());
}

bool	Fixed::operator<( const Fixed& b ) const
{
	return (this->getRawBits() < b.getRawBits());
}

bool	Fixed::operator==( const Fixed& b ) const
{
	return (this->getRawBits() == b.getRawBits());
}

bool	Fixed::operator!=( const Fixed& b ) const
{
	return (this->getRawBits() != b.getRawBits());
}

bool	Fixed::operator<=( const Fixed& b ) const
{
	return (!(this->getRawBits() > b.getRawBits()));
}

bool	Fixed::operator>=( const Fixed& b ) const
{
	return (!(this->getRawBits() < b.getRawBits()));
}




Fixed	Fixed::operator+( const Fixed& b ) const
{
	Fixed	tmp;

	tmp.setRawBits(this->getRawBits() + b.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator-( const Fixed& b ) const
{
	Fixed	tmp;

	tmp.setRawBits(this->getRawBits() - b.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator*( const Fixed& b ) const
{
	Fixed	tmp;

	tmp.setRawBits((this->getRawBits() * b.getRawBits()) >> this->getBinaryPoint());
	return (tmp);
}

Fixed	Fixed::operator/( const Fixed& b ) const
{
	Fixed	tmp;

	tmp.setRawBits((this->getRawBits() / b.getRawBits()) << this->getBinaryPoint());
	return (tmp);
}

int		Fixed::getBinaryPoint( void ) const
{
	return this->b_point;
}

Fixed&	Fixed::operator++( void )
{
	(this->value)++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	old;

	old = *this;
	(this->value)++;
	return (old);
}

Fixed&	Fixed::operator--( void )
{
	(this->value)--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	old;

	old = *this;
	(this->value)--;
	return (old);
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
