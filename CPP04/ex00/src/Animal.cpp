/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:27:53 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/10 10:27:53 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Animal constructor called" << std::endl;
	this->type = "Animal";
}
Animal::Animal( Animal& copy )
{
	std::cout << "Copy Animal constructor called" << std::endl;
	this->type = copy.getType();
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string		Animal::getType( void ) const
{
	return this->type;
}

void	Animal::setType( std::string name)
{
	this->type = name;
}

void	Animal::operator=(Animal& copy)
{
	std::cout << "Copy Animal assignment operator called" << std::endl;
	this->type = copy.getType();
}

void Animal::makeSound() const
{
	std::cout << "*INCOMPREHENSIBLE NOIZES*" << std::endl;
}
