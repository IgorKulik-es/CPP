/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:34:44 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/12 12:34:53 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap	droid_1("R2-D2");


	droid_1.attack("Random object");
	droid_1.beRepaired(5);
	droid_1.highFivesGuys();
	droid_1.guardGate();
	droid_1.whoAmI();

	return 0;
}
