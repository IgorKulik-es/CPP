/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:12:57 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/02 20:35:50 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <vector>
# include <iostream>
# include <exception>
# include <cstdlib>
# include <sys/time.h>
# define M_LIST 1
# define M_DEQUE 2
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
		int			mode;
		static int	jacobsthal( int n);
	public:
		void		insert_tail( T& tail);
		void		sort_pairs( void );
		static void	move_pair( T& where, Iterator target, T& other, Iterator first, int size, int mode );
		static void	assign_tail_pos( std::vector<int>& distances, int min_dist, int size );
		static void	update_tail_pos( std::vector<int>& distances, int added_pos, int size );
		static void	store_tail_pos_list( Iterator *pairs);
		void		extract_tail( T& tail );
		Iterator	binary_search( Iterator value, Iterator start, Iterator end );
		void		insert_one_pair( T& tail, std::vector<int>& distances, int pos);
		PmergeMe( int mode );
		PmergeMe( const PmergeMe& other );
		~PmergeMe();
		PmergeMe&	operator=( const PmergeMe& other);
		const T&	getBase( void ) const;
		int			getSize( void ) const;

		T*		scan_numbers( int argc, char ** argv );
		void	sort( void );
		void	print_numbers( void );

		class InvalidMode: public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

# include "PmergeMe.tpp"

#endif
