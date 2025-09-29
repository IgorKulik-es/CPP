/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:35:34 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/29 13:37:53 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP
# define __STDC_LIMIT_MACROS
# include <stdint.h>
# include <vector>
# include <algorithm>
# include <iostream>
# include <exception>

class Span
{
	private:
		std::vector<int>	content;
		const unsigned int	max_n;
	public:
		Span( unsigned int N );
		Span( const Span& copy );
		~Span();
		Span&				operator=( const Span& copy );
		unsigned int		getMaxN( void ) const;
		const std::vector<int>&	getContent ( void ) const;

		void	addNumber( int num_add );
		int	shortestSpan( void ) const;
		int	longestSpan( void ) const;
		void	addSpan( std::vector<int>::const_iterator first, std::vector<int>::const_iterator last );

		class InsufficientSize: public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class TooFewMembers: public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#endif
