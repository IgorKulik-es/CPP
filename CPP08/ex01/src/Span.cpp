/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:44:11 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/24 15:00:13 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int N): max_n(N)
{
}

Span::Span( const Span& copy ): max_n(copy.getMaxN())
{
	*this = copy;
}

Span::~Span() {};

Span&	Span::operator=( const Span& copy )
{
	if (this->max_n < copy.getContent().size())
		throw InsufficientSize();
	this->content.erase(this->content.begin(), this->content.end());
	this->content.insert(this->content.begin(), copy.getContent().begin(), copy.getContent().end());
	return (*this);
}

unsigned int	Span::getMaxN( void ) const
{
	return (this->max_n);
}

const std::vector<int>&	Span::getContent ( void ) const
{
	return (this->content);
}

void	Span::addNumber( int num_add )
{
	if (this->content.size() == this->max_n)
		throw InsufficientSize();
	this->content.push_back(num_add);
}

int	Span::shortestSpan( void ) const
{
	std::vector<int>			copy = this->content;
	std::vector<int>::iterator	iter = (copy.begin())++;
	int							min_diff = INT32_MAX;
	int							current_diff;

	std::sort(copy.begin(), copy.end());
	for ( ; iter < copy.end(); iter++)
	{
		current_diff = abs(*(iter - 1) - *iter);
		if (current_diff < min_diff)
			min_diff = current_diff;
	}
	return (min_diff);
}

int	Span::longestSpan( void ) const
{
	std::vector<int>::const_iterator	start;
	std::vector<int>::const_iterator	end;
	int									max_diff;

	start = this->content.begin();
	end = this->content.end();
	max_diff = *(std::max_element(start, end)) - *(std::min_element(start, end));
	return (max_diff);
}

void	Span::addSpan( std::vector<int>::const_iterator first, std::vector<int>::const_iterator last )
{
	unsigned int	new_size;

	new_size = last - first + 1 + this->content.size();
	if (new_size > this->max_n)
		throw InsufficientSize();
	this->content.insert(this->content.end(), first, last);
}

const char*	Span::InsufficientSize::what() const throw()
{
	return ("Span::InsufficentSize");
}
