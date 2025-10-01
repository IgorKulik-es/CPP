/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:12:57 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/01 15:59:02 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <deque>
# include <vector>
# include <iostream>
# define M_LIST 1
# define M_DEQUE 2


template <typename T, typename Iterator>
class PmergeMe
{
	private:
		T			base;
		int			size;
		int			half_size;
		int			mode;
		void		insert_tail( T& tail, int step );
		void		sort_pairs( int step );
		static void	move_pair( Iterator target, T& other, Iterator first, int size, int mode );
		void		extract_tail( T& tail, int pair_size);
		static int	jacobsthal( int n);
	public:
		PmergeMe( int mode );
		PmergeMe( const PmergeMe& other );
		~PmergeMe();
		PmergeMe&	operator=( const PmergeMe& other);
		const T&	getBase( void ) const;

		T*	scan_numbers( int argc, char ** argv );
		T*	sort( void );
};

#endif
