/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriSource.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:49:56 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 16:13:17 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource( )
{
	for (int i = 0; i < MAX_MATERIA_S; i++)
		this->inventory[i] = NULL;
}
MateriaSource::MateriaSource( const MateriaSource& copy )
{
	for (int i = 0; i < MAX_MATERIA_S; i++)
		this->inventory[i] = NULL;
	*this = copy;
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA_S; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		this->inventory[i] = NULL;
	}
}

const AMateria*	MateriaSource::getMateria( int index) const
{
	return this->inventory[index];
}

void	MateriaSource::operator=( const MateriaSource& copy )
{
	for (int i = 0; i < MAX_MATERIA_S; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		this->inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_MATERIA_S; i++)
	{
		if (copy.getMateria(i) != NULL)
			this->inventory[i] = copy.getMateria(i)->clone();
	}
}

void	MateriaSource::learnMateria( AMateria* m )
{
	int	index = 0;

	while (this->inventory[4] != NULL && index < MAX_MATERIA_S)
		index++;
	if (index < MAX_MATERIA_S)
	{
		std::cout << "Materia Source: " << m->getType() << " learned"<< std::endl;
		this->inventory[index] = m;
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	int			index = 0;
	AMateria	*find = NULL;

	while (index < MAX_MATERIA_S && this->inventory[index]->getType() != type)
		index++;
	if (index < MAX_MATERIA_S)
		find = this->inventory[index]->clone();
	return find;
}
