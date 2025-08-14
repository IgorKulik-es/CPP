/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:43:30 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 15:40:30 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character( const std::string& name )
{
	this->name = name;
	for (int i = 0; i < MAX_MATERIAS; i++)
		this->inventory[i] = NULL;
}
Character::Character( const Character& copy )
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		this->inventory[i] = NULL;
	*this = copy;
}
Character::~Character()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		this->inventory[i] = NULL;
	}
}

const std::string&	Character::getName( void ) const
{
	return this->name;
}

void	Character::setName( const std::string& name)
{
	this->name = name;
}

const AMateria*	Character::getMateria( int index) const
{
	return this->inventory[index];
}

void	Character::operator=( const Character& copy )
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		this->inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (copy.getMateria(i) != NULL)
			this->inventory[i] = copy.getMateria(i)->clone();
	}
	this->name = copy.getName();
}

void Character::equip(AMateria* m)
{
	int	index = 0;

	while (this->inventory[4] != NULL && index < MAX_MATERIAS)
		index++;
	if (index < MAX_MATERIAS)
	{
		std::cout << this->name << " equips " << m->getType() << std::endl;
		this->inventory[index] = m;
	}
}

void Character::unequip(int idx)
{
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}

