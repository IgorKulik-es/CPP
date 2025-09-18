/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:15:27 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/18 17:24:07 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# define T_CHAR 'c'
# define T_INT 'i'
# define T_FLOAT 'f'
# define T_DOUBLE 'd'
# define T_NOTFOUND 0

# include <iostream>
# include <string>
# include <typeinfo>
# include <cstdlib>

class	ScalarConverter
{	private:
		static void	print_type( std::string number, char type );
		static void	print_char( char c );
		static void	print_int( int	i );
		static void	print_float( float f );
		static void	print_double( double d );
		static char	get_type( std::string number );
		static void	correct_char( char c );
	public:
		ScalarConverter();
		ScalarConverter( const ScalarConverter& copy );
		virtual ~ScalarConverter() = 0;
		void		operator=( const ScalarConverter& copy );
		static void	convert(std::string number);
};

#endif
