/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:24:40 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 17:29:01 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}
WrongCat::WrongCat( WrongCat& copy ) : WrongAnimal::WrongAnimal( copy )
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string		WrongCat::getType( void ) const
{
	return this->type;
}

void	WrongCat::setType( std::string name)
{
	this->type = name;
}

void	WrongCat::operator=(WrongCat& copy)
{
	std::cout << "Copy WrongCat assignment operator called" << std::endl;
	this->type = copy.getType();
}

void WrongCat::makeSound() const
{
	std::cout << "*KWAK*" << std::endl;
}
