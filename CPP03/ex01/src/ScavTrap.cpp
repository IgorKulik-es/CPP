/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:27:53 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/11 15:11:25 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setAttackDamage(20);
	this->setEnegryPoints(50);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode" << std::endl;
}
