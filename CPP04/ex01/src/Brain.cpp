/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:14:20 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 19:27:41 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
}
Brain::Brain( Brain& copy )
{
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = copy;
}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string		Brain::getIdea( int index ) const
{
	return this->ideas[index];
}

void	Brain::setIdea( std::string& idea, int index)
{
	this->ideas[index] = idea;
}

void	Brain::operator=(Brain& copy)
{
	std::cout << "Copy Brain assignment operator called" << std::endl;
	for (int i = 0; i < BRAIN_SIZE; i++)
		this->ideas[i] = copy.getIdea(i);
}
