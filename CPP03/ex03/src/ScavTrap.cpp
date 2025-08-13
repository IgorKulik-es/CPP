/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:27:53 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/12 12:43:04 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap::ClapTrap( name )
{
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
}

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cout << "Repairs needed!" << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << "Not enough energy points!" << std::endl;
		return ;
	}
	(this->energy_points)--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing ";
	std::cout << this->attack_damage << " points of damage!" << std::endl;
}
