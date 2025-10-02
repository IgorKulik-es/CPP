/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:24:09 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/02 20:40:40 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename Iterator>
PmergeMe<T, Iterator>::PmergeMe( int mode ): size(0), half_size(0), mode(mode)
{
	if (mode != M_LIST && mode != M_DEQUE)
		throw InvalidMode();
};

template <typename T, typename Iterator>
int	PmergeMe<T, Iterator>::pair_size = 2;

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
const char*	PmergeMe<T, Iterator>::InvalidMode::what() const throw()
{
	return ("PmergeMe::InvalidMode");
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
int	PmergeMe<T, Iterator>::getSize( void ) const
{
	return (this->size);
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
			this->base.clear();
			return (NULL);
		}
		base.push_back(num);
	}
	this->size = base.size();
	this->half_size = this->size / 2;
	return (&(this->base));
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::sort( )
{
	this->sort_pairs();
	pair_size *= 2;
	if (pair_size < this->half_size)
		this->sort();
	pair_size /= 2;

	T	tail;
	extract_tail(tail, pair_size);
	insert_tail(tail);
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::sort_pairs( void )
{
	Iterator	iter;
	Iterator	midle;
	int			half_pair = this->pair_size / 2;
	int			num_pairs = this->base.size() / pair_size;
	int			position = pair_size - 1;

	for (int i = 1; i < num_pairs; i++)
	{
		iter = this->base.begin();
		std::advance(iter, position);
		midle = iter;
		std::advance(midle, - half_pair);
		if (*iter < *midle)
		{
			std::advance(iter, - pair_size);
			std::advance(midle, 1);
			move_pair(this->base, iter, this->base, midle, half_pair, this->mode);
		}
		position += pair_size;
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::move_pair( T& where, Iterator target, T& other, Iterator first, int size, int mode )
{
	(void)other;
	(void)mode;
/* 	if (mode == M_LIST)
		T::splice(target, other, first, size + 1);
	else if (mode == M_DEQUE)
	{ */
		T	temp;
		Iterator	last = first;
		std::advance(last, size - 1);

		temp.insert(temp.begin(), first, last);
		other.erase(first, last);
		last = temp.end();
		std::advance(last, -1);
		where.insert(target, temp.begin(), temp.end() - 1);
/* 	} */
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::extract_tail( T& tail, int pair_size)
{
	int			position = pair_size + pair_size;
	int			last_pair = this->size - pair_size;
	Iterator	take_out;

	while (position <= last_pair)
	{
		take_out = this->base.begin();
		std::advance(take_out, position);
		move_pair(tail, tail.end(), this->base, take_out, pair_size, this->mode);
		position += pair_size;
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::insert_tail( T& tail )
{
	int	idx_jacob = 3;
	int	jacob = 3;
	int	step_jacob = 2;
	int	pairs_left = tail.size() / pair_size;
	std::vector<int>	distances;

	while (!tail.empty())
	{
		if (step_jacob > pairs_left)
			step_jacob = pairs_left;
		assign_tail_pos(distances, jacob + 1, step_jacob);
		for (int i = step_jacob; i > 0; i--)
			this->insert_one_pair(tail, distances, i);
		pairs_left -= step_jacob;
		step_jacob = jacob;
		jacob = jacobsthal(++idx_jacob);
		step_jacob = jacob - step_jacob;

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
	if (n >= (int)nums.size())
	{
		for (int i = nums.size(); i <= n; i++)
			nums.push_back(nums[i - 2] * 2 + nums[i - 1]);
	}
	return (nums[n]);
}

template <typename T, typename Iterator>
Iterator	PmergeMe<T, Iterator>::binary_search( Iterator value, Iterator start, Iterator end )
{
	Iterator	current = this->base.begin();
	int			dist;

	dist = std::distance(start, end);
	if (dist == 0)
		return (start);
	std::advance(current,  (dist / 2) * pair_size);
	if (*value < *current)
	{
		if (dist == 1)
			return (start);
		std::advance(current, -1);
		return (this->binary_search(value, start, current));
	}
	else
	{
		if (dist == 1)
			return (end);
		std::advance(current, 1);
		return (this->binary_search(value, current, end));
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::assign_tail_pos( std::vector<int> distances, int min_dist, int size )
{
	for (int i = 0; i < size; i++)
		distances[i] = min_dist + i;
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::update_tail_pos( std::vector<int> distances, int added_pos, int size )
{
	for (int i = 0; i < size; i++)
	{
		if (distances[i] >= added_pos)
			(distances[i])++;
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::insert_one_pair( T& tail, std::vector<int>& distances, int pos)
{

	Iterator	to_find;
	Iterator	to_insert;
	Iterator	start;
	Iterator	end;

	to_find = tail.begin();
	std::advance(to_find, pos * pair_size - 1);
	start = this->base.begin();
	std::advance(start, pair_size - 1);
	end = this->base.begin();
	std::advance(end, distances[pos - 1] * pair_size - 1);
	to_insert = this->binary_search(to_find, start, end);
	update_tail_pos(distances, std::distance(this->base.begin(), to_insert) / pair_size, pos - 1);
	std::advance(to_insert, -pair_size + 1);
	start = to_find;
	std::advance(start, -pair_size + 1);
	move_pair(to_insert, tail, start, pair_size, this->mode);
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::print_numbers( void )
{
	Iterator	index = this->base.begin();
	Iterator	end = this->base.end();
	while (index != end)
	{
		std::cout << *index << " ";
		std::advance(index, 1);
	}
	std::cout << std::endl;
}


