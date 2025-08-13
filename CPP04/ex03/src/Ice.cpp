/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:53:58 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 00:53:58 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice( const std::string& type ) : AMateria::AMateria( type )
{
}
Ice::Ice( const Ice& copy )
{
	*this = copy;
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
	return new Ice(this->type);
}
