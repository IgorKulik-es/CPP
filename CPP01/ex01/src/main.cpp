/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:48:17 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/02 12:48:17 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main( void )
{
	Zombie	*zombie_ptr;
	int		nb_horde = 5;
	
	zombie_ptr = zombieHorde(nb_horde, "Jason");
	for (int i = 0; i < nb_horde; i++)
		zombie_ptr[i].announce();
	delete[] zombie_ptr;
	return (0);
}