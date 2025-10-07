/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:12:57 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/07 20:00:23 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <deque>
# include <vector>
# include <iostream>
# include <exception>
# include <cstdlib>
# include <sys/time.h>
# define MILLISEC 1000000


template <typename T, typename Iterator>
class PmergeMe
{
	private:
		T			base;
		int			size;
		int			half_size;
		static int	pair_size;
		static int	half_pair;
		static int	num_comps;
		static int	jacobsthal( int n);
		void		insert_tail( T& tail);
		void		sort_pairs( void );
		static void	assign_tail_pos( std::vector<int>& distances, int min_dist, int size );
		void	update_tail_pos( std::vector<int>& distances, int added_pos, int size );
		void		extract_tail( T& tail );
		Iterator	binary_search( Iterator value, Iterator start, Iterator end, Iterator very_end );
		void		insert_one_pair( T& tail, std::vector<int>& distances, int pos);
	public:
		void	move_pair( T& where, Iterator target, T& other, Iterator first, int size );
		PmergeMe();
		PmergeMe( const PmergeMe& other );
		~PmergeMe();
		PmergeMe&	operator=( const PmergeMe& other);
		/* const  */T&	getBase( void ) ;//const;
		int			getSize( void ) const;
		static int	getNumComps( void );
		static void	resetNumOps( void );

		T*		scan_numbers( int argc, char ** argv );
		void	sort( void );
		void	print_numbers( void );

};

# include "PmergeMe.tpp"

#endif
