/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:46:06 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 17:46:46 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "../include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat( );
		WrongCat( WrongCat& copy );
		~WrongCat();
		void	operator=(WrongCat& copy);
		std::string		getType( void ) const;
		void			setType( std::string name );

		void makeSound() const;
};

#endif
