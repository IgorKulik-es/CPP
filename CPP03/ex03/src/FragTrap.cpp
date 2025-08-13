/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:31:28 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/12 12:47:08 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap::ClapTrap( name )
{
	this->hit_points = 100;
	this->attack_damage = 30;
	this->energy_points = 100;
}

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->getName() << " invites you to give him five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
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
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing ";
	std::cout << this->attack_damage << " points of damage!" << std::endl;
}
