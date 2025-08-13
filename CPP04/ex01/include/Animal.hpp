/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:14:51 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 17:27:42 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal( );
		Animal( Animal& copy );
		virtual ~Animal();
		void	operator=(Animal& copy);
		std::string		getType( void ) const;
		void			setType( std::string name );

		virtual void makeSound() const;
};

#endif
