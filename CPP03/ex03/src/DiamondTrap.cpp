/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:14:24 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/12 13:14:41 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap::ClapTrap( name + "_clap_name" )
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->attack_damage = 30;
	this->energy_points = 50;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap name: " << this->name;
	std::cout << ", ClapTrap name: " << this->ClapTrap::name << std::endl;
}
