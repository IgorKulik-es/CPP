/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:34:44 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/10 10:34:44 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main( void )
{
	ClapTrap	droid_1("C-3PO");
	ClapTrap	droid_2("R2-D2");
	ClapTrap	dummy("Blank");
	ClapTrap	copy ( dummy );

	dummy = droid_1;

	droid_2.setAttackDamage(3);
	droid_2.attack(droid_1.getName());
	droid_1.takeDamage(droid_2.getAttackDamage());
	droid_2.attack(droid_1.getName());
	droid_1.takeDamage(droid_2.getAttackDamage());
	droid_1.beRepaired(2);
	droid_2.setEnegryPoints(0);
	droid_2.attack(droid_1.getName());
	droid_2.beRepaired(4);

	return 0;
}