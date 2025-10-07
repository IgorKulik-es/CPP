/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:24:09 by ikulik            #+#    #+#             */
/*   Updated: 2025/10/07 20:44:48 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename Iterator>
PmergeMe<T, Iterator>::PmergeMe(): size(0), half_size(0)
{
};

template <typename T, typename Iterator>
int	PmergeMe<T, Iterator>::pair_size = 2;

template <typename T, typename Iterator>
int	PmergeMe<T, Iterator>::half_pair = 1;

template <typename T, typename Iterator>
int	PmergeMe<T, Iterator>::num_comps = 0;

template <typename T, typename Iterator>
PmergeMe<T, Iterator>::PmergeMe( const PmergeMe<T, Iterator>& copy )
{
	*this = copy;
}

template <typename T, typename Iterator>
PmergeMe<T, Iterator>::~PmergeMe(){};

template <typename T, typename Iterator>
/* const  */T&	PmergeMe<T, Iterator>::getBase( void ) //const
{
	return (this->base);
}

template <typename T, typename Iterator>
PmergeMe<T, Iterator>&	PmergeMe<T, Iterator>::operator=( const PmergeMe<T, Iterator>& copy )
{
	this->base.clear();
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
int	PmergeMe<T, Iterator>::getNumComps( void )
{
	return (num_comps);
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::resetNumOps( void )
{
	num_comps = 0;
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
void	PmergeMe<T, Iterator>::sort( void )
{
	this->sort_pairs();
	//std::cout << "Sorting pairs, size " << pair_size << " ";
	//this->print_numbers();
	pair_size *= 2;
	half_pair *= 2;
	if (pair_size <= this->size)
		this->sort();
	pair_size /= 2;
	half_pair /= 2;

	T	tail;
	std::cout << "Before extraction:\t";
	this->print_numbers();
	extract_tail(tail);
	insert_tail(tail);
	std::cout << "After inserting:\t";
	this->print_numbers();
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::sort_pairs( void )
{
	Iterator	iter;
	Iterator	middle;
	int			num_pairs = this->base.size() / pair_size;
	int			position = pair_size - 1;

	for (int i = 0; i < num_pairs; i++)
	{
		iter = this->base.begin();
		std::advance(iter, position);
		middle = iter;
		std::advance(middle, - half_pair);
		num_comps++;
		std::cout << "Comp " << *iter << " " << *middle << "| ";
		if (*iter < *middle)
		{
			std::advance(iter, -pair_size + 1);
			std::advance(middle, 1);
			move_pair(this->base, iter, this->base, middle, half_pair);
		}
		position += pair_size;
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::move_pair( T& where, Iterator target, T& other, Iterator first, int size )
{
	T	temp;
	Iterator	last = first;
	std::advance(last, size);

	temp.insert(temp.end(), first, last);
	other.erase(first, last);
	std::cout << "First elt " << *(temp.begin()) << "\n";
	last = temp.end();
	if (target != where.end())
		std::cout << "Inserting " << *(temp.begin()) << " before " << *target << "\n";
	where.insert(target, temp.begin(), last);
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
	while (pairs_to_extract > 0)
	{
		take_out = this->base.begin();
		std::advance(take_out, position);
		move_pair(tail, tail.end(), this->base, take_out, half_pair);
		position += half_pair;
		pairs_to_extract--;
	}
}

template <typename T, typename Iterator>
void	PmergeMe<T, Iterator>::insert_tail( T& tail )
{
	int	idx_jacob = 3;
	int	old_jacob = 1;
	int	jacob = 3;
	int	step_jacob = 2;
	int	pairs_left = tail.size() / half_pair;
	std::vector<int>	distances;

	while (pairs_left)
	{
		if (step_jacob > pairs_left)
			step_jacob = pairs_left;
		assign_tail_pos(distances, old_jacob * 2, step_jacob);
		for (int i = step_jacob; i > 0; i--)
			this->insert_one_pair(tail, distances, i);
		/* else
			for (int i = 1; i <= pairs_left; i++)
				this->insert_one_pair(tail, distances, i); */
		distances.clear();
		pairs_left -= step_jacob;
		old_jacob = jacob;
		jacob = jacobsthal(++idx_jacob);
		step_jacob = jacob - old_jacob;
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
Iterator	PmergeMe<T, Iterator>::binary_search( Iterator value, Iterator start, Iterator end, Iterator very_end )
{
	Iterator	current = start;
	int			dist;

	dist = std::distance(start, end) / half_pair;
	if (dist == 0)
	{
		num_comps++;
		std::cout << "Comp1 " << *value << " " << *current << "| ";
		if (*value > *start)
		{
			std::advance(start, 1);
			if (start != very_end)
				std::advance(start, half_pair - 1);
			else
				std::cout << "hello";
		}
		return (start);
	}
	std::advance(current, (dist / 2) * half_pair);
	num_comps++;
	std::cout << "Comp2 " << *value << " " << *current << "| ";
	if (*value < *current)
	{
		if (dist == 1)
			return (start);
		std::advance(current, -half_pair);
		return (this->binary_search(value, start, current, very_end));
	}
	else
	{
		if (dist == 1)
		{
			num_comps++;
			std::cout << "Comp3 " << *value << " " << *end << "| ";
			if (*value > *end)
			{
				std::advance(end, 1);
				std::cout << "very end " << *very_end << std::endl;
				if (end != very_end)
					std::advance(end, half_pair - 1);
				else
					std::cout << "hello";
			}
			return (end);
		}
		std::advance(current, half_pair);
		return (this->binary_search(value, current, end, very_end));
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
		if (distances[i] >= added_pos - 1)
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
	Iterator	border;

	to_find = tail.begin();
	std::advance(to_find, pos * half_pair - 1);
	start = this->base.begin();
	std::advance(start, half_pair - 1);
	end = this->base.begin();
	std::advance(end, (distances[pos - 1]) * half_pair - 1);
	border = this->base.end();
	std::advance(border, -(this->base.size() % half_pair));
	std::cout << "Searching between " << *start << " " << *end << " dist " << (distances[pos - 1]) * half_pair - 1 << " array " << distances[pos - 1] << std::endl;
	to_insert = this->binary_search(to_find, start, end, border);
	this->update_tail_pos(distances, (std::distance(this->base.begin(), to_insert) + 1) / half_pair, pos - 1);
	if (to_insert != border)
		std::advance(to_insert, -half_pair + 1);
	start = to_find;
	std::advance(start, -half_pair + 1);
	move_pair(this->base, to_insert, tail, start, half_pair);
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


