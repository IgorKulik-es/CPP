/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:30:03 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 17:09:35 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Cat_HPP
#define Cat_HPP

#include "../include/Animal.hpp"

class Cat : public Animal
{
	public:
		Cat( );
		Cat( Cat& copy );
		~Cat();
		void	operator=(Cat& copy);
		std::string		getType( void ) const;
		void			setType( std::string name );

		void makeSound() const;
};

#endif
