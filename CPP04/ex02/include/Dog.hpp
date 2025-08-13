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
#include "../include/Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;
	public:
		Dog( );
		Dog( Dog& copy );
		~Dog();
		void	operator=(Dog& copy);
		Brain*			getBrain( void ) const;
		void			setBrain( Brain& new_brain);

		void makeSound() const;
};

#endif
