/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:53:58 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 16:54:58 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
#include "../include/Character.hpp"

Ice::Ice( ) : AMateria::AMateria( "ice" )
{
}
Ice::Ice( const Ice& copy ) : AMateria::AMateria( copy )
{
}
Ice::~Ice()
{
}
void	Ice::operator=( const Ice& copy )
{
	this->type = copy.getType();
}

Ice*	Ice::clone() const
{
	return new Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

