/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:14:51 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 16:19:01 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "../include/Animal.hpp"

class Dog : public Animal
{
	public:
		Dog( );
		Dog( Dog& copy );
		~Dog();
		void	operator=(Dog& copy);
		std::string		getType( void ) const;
		void			setType( std::string name );

		void makeSound() const;
};

#endif
