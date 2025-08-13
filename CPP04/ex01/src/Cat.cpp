/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:24:40 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 19:40:00 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}
Cat::Cat( Cat& copy ) : Animal::Animal( copy )
{
	std::cout << "Copy Cat constructor called" << std::endl;
	brain = new Brain();
	*this = copy;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void	Cat::operator=(Cat& copy)
{
	std::cout << "Copy Cat assignment operator called" << std::endl;
	this->type = copy.getType();
	*brain = *(copy.getBrain());
}

void Cat::makeSound() const
{
	std::cout << "*MEOW*" << std::endl;
}

Brain*	Cat::getBrain( void ) const
{
	return this->brain;
}
void	Cat::setBrain( Brain& new_brain)
{
	*(this->brain) = new_brain;
}
