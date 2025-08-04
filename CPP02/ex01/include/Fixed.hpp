/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 09:31:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/03 09:31:22 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					value;
		const static int	b_point;
	public:
		Fixed();
		Fixed( Fixed& copy );
		~Fixed();
		void	operator=(Fixed& copy);
		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
};

#endif