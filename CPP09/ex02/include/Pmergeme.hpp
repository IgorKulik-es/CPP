/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:12:57 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/30 19:26:34 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <deque>
# include <iostream>

template <typename T, typename T::iterator>
void	pmergesort( typename T::iterator start, typename T::iterator end );

template <typename T, typename T::iterator>
class Pmergeme
{
	private:
		T	base;
	public:
		T*		get_numbers(int argc, char ** argv);
		void	

}

#endif
