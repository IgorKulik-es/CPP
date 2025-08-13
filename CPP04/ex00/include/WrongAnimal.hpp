/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:32:33 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 17:51:08 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal( );
		WrongAnimal( WrongAnimal& copy );
		~WrongAnimal();
		void	operator=(WrongAnimal& copy);
		std::string		getType( void ) const;
		void			setType( std::string name );

		void makeSound() const;
};

#endif
