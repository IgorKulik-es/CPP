/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:24:40 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 17:29:01 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
}
Cat::Cat( Cat& copy ) : Animal::Animal( copy )
{
	std::cout << "Copy Cat constructor called" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

std::string		Cat::getType( void ) const
{
	return this->type;
}

void	Cat::setType( std::string name)
{
	this->type = name;
}

void	Cat::operator=(Cat& copy)
{
	std::cout << "Copy Cat assignment operator called" << std::endl;
	this->type = copy.getType();
}

void Cat::makeSound() const
{
	std::cout << "*MEOW*" << std::endl;
}
