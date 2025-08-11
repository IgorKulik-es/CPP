/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:27:53 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/10 10:27:53 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->attack_damage = 0;
	this->energy_points = 10;
}
ClapTrap::ClapTrap( ClapTrap& copy )
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	this->name = copy.getName();
	this->hit_points = copy.getHitPoints();
	this->energy_points = copy.getEnegryPoints();
	this->attack_damage = copy.getAttackDamage();
}
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

unsigned int	ClapTrap::getHitPoints( void ) const
{
	return this->hit_points;
}

unsigned int	ClapTrap::getEnegryPoints( void ) const
{
	return this->energy_points;
}

unsigned int	ClapTrap::getAttackDamage( void ) const
{
	return this->attack_damage;
}

std::string		ClapTrap::getName( void ) const
{
	return this->name;
}

void	ClapTrap::setAttackDamage( unsigned int value)
{
	this->attack_damage = value;
}

void	ClapTrap::setHitPoints( unsigned int value)
{
	this->hit_points = value;
}

void	ClapTrap::setEnegryPoints( unsigned int value)
{
	this->energy_points = value;
}

void	ClapTrap::setName( std::string name)
{
	this->name = name;
}

void	ClapTrap::operator=(ClapTrap& copy)
{
	std::cout << "Copy ClapTrap assignment operator called" << std::endl;
	this->name = copy.getName();
	this->hit_points = copy.getHitPoints();
	this->energy_points = copy.getEnegryPoints();
	this->attack_damage = copy.getAttackDamage();
}

void ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing ";
	std::cout << this->attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hit_points)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount;
	std::cout << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << this->name << " ramaining hp: " << this->hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
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
	this->hit_points += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself for " << amount;
	std::cout << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << this->name << " ramaining hp: " << this->hit_points << std::endl;
}