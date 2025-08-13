/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:27:53 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/10 10:27:53 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
	this->type = "WrongAnimal";
}
WrongAnimal::WrongAnimal( WrongAnimal& copy )
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	this->type = copy.getType();
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string		WrongAnimal::getType( void ) const
{
	return this->type;
}

void	WrongAnimal::setType( std::string name)
{
	this->type = name;
}

void	WrongAnimal::operator=(WrongAnimal& copy)
{
	std::cout << "Copy WrongAnimal assignment operator called" << std::endl;
	this->type = copy.getType();
}

void WrongAnimal::makeSound() const
{
	std::cout << "*WRONG NOIZES*" << std::endl;
}
