/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:30:03 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 19:30:16 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Cat_HPP
#define Cat_HPP

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;
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
