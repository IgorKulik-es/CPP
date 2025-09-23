/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:44:11 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/23 20:05:38 by ikulik           ###   ########.fr       */
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
	std::erase(this->content.begin(), this->content.end());
	std::insert(this->content.begin(), copy.getContent.begin(), copy.getContent.end());
}

unsigned int	Span::getMaxN( void ) const
{
	return (this->max_n);
}

unsigned int	Span::getMaxN( void ) const
{
	return (this->max_n);
}

std::vector<int>&	Span::getContent ( void ) const
{
	return (this->content);
}
