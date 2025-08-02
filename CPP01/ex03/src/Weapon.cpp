/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:57:21 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/02 13:57:21 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon( std::string name )
{
	this->type = name;
}

Weapon::~Weapon(){};

Weapon::Weapon(){};

void	Weapon::setType( std::string name)
{
	this->type = name;
}

const std::string&	Weapon::getType( void )
{
	return this->type;
}