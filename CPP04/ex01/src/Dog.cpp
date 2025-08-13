/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:24:40 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 17:29:05 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
}
Dog::Dog( Dog& copy ) : Animal::Animal( copy )
{
	std::cout << "Copy Dog constructor called" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

std::string		Dog::getType( void ) const
{
	return this->type;
}

void	Dog::setType( std::string name)
{
	this->type = name;
}

void	Dog::operator=(Dog& copy)
{
	std::cout << "Copy Dog assignment operator called" << std::endl;
	this->type = copy.getType();
}

void Dog::makeSound() const
{
	std::cout << "*BARK*" << std::endl;
}
