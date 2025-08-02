/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:08:37 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/02 13:08:37 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde_ptr;

	horde_ptr = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde_ptr[i].setName(name);
	return (horde_ptr);
}