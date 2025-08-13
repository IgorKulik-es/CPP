/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:52:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 00:52:35 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria( const std::string& type )
{
	this->type = type;
}
AMateria::AMateria( const AMateria& copy )
{
	*this = copy;
}
AMateria::~AMateria()
{
}

const std::string&	AMateria::getType( void ) const
{
	return this->type;
}

void	AMateria::setType( std::string name)
{
	this->type = name;
}

void	AMateria::operator=( const AMateria& copy )
{
	this->type = copy.getType();
}

