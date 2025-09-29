/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:45:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/29 14:46:38 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <list>
# include <deque>
# include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack();
		MutantStack( const MutantStack& copy );
		~MutantStack();
		MutantStack&	operator=( const MutantStack& copy );
		const std::deque<T>&	get_c( void ) const;
		typedef typename std::deque<T>::iterator		iterator;
		typedef typename std::deque<T>::const_iterator	const_iterator;

		iterator		begin( void );
		iterator		end( void );
		const_iterator	begin( void ) const;
		const_iterator	end( void ) const;
};

# include "MutantStack.tpp"
#endif
