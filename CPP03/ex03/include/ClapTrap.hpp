/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:22:46 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/12 13:22:05 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	public:
		ClapTrap( std::string name );
		ClapTrap();
		ClapTrap( ClapTrap& copy );
		~ClapTrap();
		void	operator=(ClapTrap& copy);
		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnegryPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;
		std::string		getName( void ) const;
		void			setHitPoints( unsigned int value );
		void			setEnegryPoints( unsigned int value );
		void			setAttackDamage( unsigned int value );
		void			setName( std::string name );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif
