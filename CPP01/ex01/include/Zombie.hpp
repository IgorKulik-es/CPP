/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:44:44 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/02 12:44:44 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		void	announce( void );
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void	setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif