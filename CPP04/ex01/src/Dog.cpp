/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:24:40 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 19:40:17 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";	
	this->brain = new Brain();
}
Dog::Dog( Dog& copy ) : Animal::Animal( copy )
{
	std::cout << "Copy Dog constructor called" << std::endl;
	this->brain = new Brain();
	*this = copy;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void	Dog::operator=(Dog& copy)
{
	std::cout << "Copy Dog assignment operator called" << std::endl;
	this->type = copy.getType();
	*brain = *(copy.getBrain());
}

void Dog::makeSound() const
{
	std::cout << "*BARK*" << std::endl;
}

Brain*	Dog::getBrain( void ) const
{
	return this->brain;
}
void	Dog::setBrain( Brain& new_brain)
{
	*(this->brain) = new_brain;
}
