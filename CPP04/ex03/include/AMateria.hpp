/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:39:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 00:39:22 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria( const std::string& type );
		AMateria( const AMateria& copy );
		~AMateria();
		void				operator=( const AMateria& copy);
		void				AMateria::setType( std::string name);
		const std::string&	AMateria::getType( void ) const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
