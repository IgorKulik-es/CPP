/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:22:38 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/19 15:43:54 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>
# include <cstdlib>

template <class T>
class Array
{
	private:
		unsigned int	arr_size;
		T*				elements;
	public:
		Array();
		Array( unsigned int n );
		Array( const Array& copy );
		~Array();
		Array&		operator=( const Array& copy );
		T&			operator[]( unsigned int idx );
		const T&	operator[]( unsigned int idx ) const;
		unsigned int	size( void ) const;
};

# include "Array.tpp"
#endif
