/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:53:58 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 15:38:47 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

Cure::Cure( const std::string& type ) : AMateria::AMateria( type )
{
}
Cure::Cure( const Cure& copy ) : AMateria::AMateria( copy )
{
}
Cure::~Cure()
{
}
void	Cure::operator=( const Cure& copy )
{
	this->type = copy.getType();
}

Cure*	Cure::clone() const
{
	return new Cure(this->type);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
