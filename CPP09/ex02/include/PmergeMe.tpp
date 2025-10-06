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
int	PmergeMe<T, Iterator>::half_pair = 1;

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
	std::cout << "Pair size "<< pair_size <<" after sorting pairs ";
	this->print_numbers();
	pair_size *= 2;
	half_pair *= 2;
	if (pair_size <= this->size)
		this->sort();
	pair_size /= 2;
	half_pair /= 2;

	T	tail;
	extract_tail(tail);
	insert_tail(tail);
	std::cout << "Pair size " << pair_size << " after insertion\t";
	this->print_numbers();
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::sort_pairs( void )
{
	Iterator	iter;
	Iterator	midle;
	int			num_pairs = this->base.size() / pair_size;
	int			position = pair_size - 1;

	for (int i = 0; i < num_pairs; i++)
	{
		iter = this->base.begin();
		std::advance(iter, position);
		midle = iter;
		std::advance(midle, - half_pair);
		if (*iter < *midle)
		{
			std::advance(iter, -pair_size + 1);
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
		std::advance(last, size);

		temp.insert(temp.end(), first, last);
		other.erase(first, last);
		last = temp.end();
		where.insert(target, temp.begin(), last);
/* 	} */
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::extract_tail( T& tail )
{
	int			position = pair_size;
	int			pairs_to_extract = this->size / pair_size - 1;
	Iterator	take_out;

	(void)tail;
	if (this->size % pair_size >= half_pair)
		pairs_to_extract++;
	std::cout << "Extracting pos " << position << " last pair " << pairs_to_extract << std::endl;
	while (pairs_to_extract > 0)
	{
		take_out = this->base.begin();
		std::advance(take_out, position);
		std::cout << "Moving " << *take_out << std::endl;
		move_pair(tail, tail.end(), this->base, take_out, half_pair, this->mode);
		position += half_pair;
		pairs_to_extract--;
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::insert_tail( T& tail )
{
	int	idx_jacob = 3;
	int	jacob = 1;
	int	step_jacob = 2;
	int	pairs_left = tail.size() / half_pair;
	std::vector<int>	distances;

	while (pairs_left)
	{
		if (step_jacob > pairs_left)
			step_jacob = pairs_left;
		assign_tail_pos(distances, jacob + 1, step_jacob);
		for (int i = step_jacob; i > 0; i--)
			this->insert_one_pair(tail, distances, i);
		distances.clear();
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
	Iterator	current = start;
	int			dist;

	dist = std::distance(start, end) / half_pair;
	if (dist == 0)
		return (start);
	std::advance(current, (dist / 2) * half_pair);
	if (*value < *current)
	{
		if (dist == 1)
			return (start);
		return (this->binary_search(value, start, current));
	}
	else
	{
		if (dist == 1)
		{
			if (*current > *end)
				std::advance(end, 1);
			return (end);
		}
		return (this->binary_search(value, current, end));
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::assign_tail_pos( std::vector<int>& distances, int min_dist, int size )
{
	for (int i = 0; i < size; i++)
		distances.push_back(min_dist + i);
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::update_tail_pos( std::vector<int>& distances, int added_pos, int size )
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
	std::advance(to_find, pos * half_pair - 1);
	start = this->base.begin();
	std::advance(start, half_pair - 1);
	end = this->base.begin();
	std::advance(end, distances[pos - 1] * half_pair - 1);
	std::cout << "Advancing by " << distances[pos - 1] << " end " << *end << " main size " << this->base.size() << std::endl;
	//std::cout << "Looking for " << *to_find	<< " within " << *start << " " << *end << std::endl;
	to_insert = this->binary_search(to_find, start, end);
	update_tail_pos(distances, (std::distance(this->base.begin(), to_insert) + 1) / half_pair, pos - 1);
	std::cout << " Found place: " << *to_insert << std::endl;
	std::advance(to_insert, -half_pair + 1);
	start = to_find;
	std::advance(start, -half_pair + 1);
	move_pair(this->base, to_insert, tail, start, half_pair, this->mode);
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


