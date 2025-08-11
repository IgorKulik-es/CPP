/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 09:31:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/11 17:32:57 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		const static int	b_point;
	public:
		Fixed();
		Fixed( const int nb );
		Fixed( const float nb );
		Fixed( const Fixed& copy );
		~Fixed();
		void	operator=(const Fixed& copy);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		getBinaryPoint( void ) const;
		float	toFloat( void ) const;
		int		toInt( void ) const;
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<( std::ostream &outstream, const Fixed& obj);
bool			operator>(const Fixed& a, const Fixed& b);
bool			operator<(const Fixed& a, const Fixed& b);
bool			operator==(const Fixed& a, const Fixed& b);
bool			operator!=(const Fixed& a, const Fixed& b);
Fixed			operator+(const Fixed& a, const Fixed& b);
Fixed			operator-(const Fixed& a, const Fixed& b);
Fixed			operator*(const Fixed& a, const Fixed& b);
Fixed			operator/(const Fixed& a, const Fixed& b);


#endif
