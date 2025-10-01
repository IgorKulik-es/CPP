/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:24:09 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/01 16:46:07 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmergeme.hpp"

template <typename T, typename Iterator>
PmergeMe<T, Iterator>::PmergeMe( int mode ): size(0), half_size(0), mode(mode)
{
};

template <typename T, typename Iterator>
PmergeMe<T, Iterator>::PmergeMe( const PmergeMe<T, Iterator>& copy )
{
	*this = copy;
}

template <typename T, typename Iterator>
PmergeMe<T, Iterator>::~PmergeMe(){};

template <typename T, typename Iterator>
const T&	PmergeMe<T, Iterator>::getBase( void ) const
{
	return (this->base);
}

template <typename T, typename Iterator>
PmergeMe<T, Iterator>&	PmergeMe<T, Iterator>::operator=( const PmergeMe<T, Iterator>& copy )
{
	this->base.erase();
	this->base = copy.getBase();
	this->size = this->base.size();
	this->half_size = this->size / 2;
}

template <typename T, typename Iterator>
T*	PmergeMe<T, Iterator>::scan_numbers( int argc, char ** argv )
{
	int	num;

	if (argc <= 1)
		return (NULL);
	for (int i = 1; i < argc; i++)
	{
		num = atoi(argv[i]);
		if (num < 0)
		{
			this->base.erase();
			return (NULL);
		}
		base.push_back(num);
	}
	return (&(this->base));
}

template <typename T, typename Iterator>
T*	PmergeMe<T, Iterator>::sort( )
{
	static int	pair_size = 2;
	this->sort_pairs( pair_size );
	pair_size *= 2;
	if (pair_size < this->half_size)
		this->sort();
	pair_size /= 2;

	T	tail;
	extract_tail(tail, pair_size);

}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::sort_pairs( int pair_size )
{
	Iterator	iter;
	int			num_pairs = this->base.size() / pair_size;
	int			position = pair_size - 1;

	for (int i = 1; i < num_pairs; i++)
	{
		iter = this->base.begin() + position;
		if (*iter < *(iter - this->half_pair))
			move_pair(iter - pair_size + 1, this->base, this->half_pair, this->mode);
		position += pair_size;
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::move_pair( Iterator target, T& other, Iterator first, int size, int mode )
{
	if (mode == M_LIST)
		T::splice(target, other, first, size + 1);
	else if (mode == M_DEQUE)
	{
		T	temp;

		T::insert(temp.begin(), first, first + size - 1);
		T::erase(first, first + size -1);
		t::insert(target, temp.begin(), temp.end() - 1);
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::extract_tail( T& tail, int pair_size)
{
	int			position = pair_size + pair_size;
	int			last_pair = this->size - pair_size;
	Iterator	take_out;

	while (position <= last_pair)
	{
		take_out = this->base.begin() + position;
		move_pair(tail.end(), this->base, take_out, pair_size, this->mode);
		position += pair_size + pair_size;
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::insert_tail( T& tail, int pair_size )
{
	int	value;
	int	direction = 1;
	int	idx_jacob = jacobsthal(3);
	int	step_jacob = 2;
	Iterator	target;

	while (!tail.empty())
	{

	}
}

template <typename T, typename Iterator>
int	PmergeMe<T, Iterator>::jacobsthal( int n)
{
	static std::vector<int>	nums;

	if (nums.empty())
	{
		nums.push_back(0);
		nums.push_back(1);
		nums.push_back(1);
	}
	if (n >= nums.size())
	{
		for (int i = nums.size(); i <= n; i++)
			nums.push_back(nums[i - 2] * 2 + nums[i - 1]);
	}
	return (nums[n]);
}

