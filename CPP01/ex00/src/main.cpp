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
	
	zombie_ptr = newZombie("Nemesis");
	zombie_ptr->announce();
	randomChump("White Walker");
	delete zombie_ptr;
	return (0);
}