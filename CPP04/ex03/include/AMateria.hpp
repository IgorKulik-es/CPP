/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:39:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 17:54:52 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
class ICharacter;

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria( const std::string& type );
		AMateria( const AMateria& copy );
		virtual ~AMateria();
		void				operator=( const AMateria& copy );
		void				setType( std::string name );
		const std::string&	getType( void ) const;
		virtual AMateria*	clone() const = 0;
		virtual void		use( ICharacter& target ) = 0;
};

#endif
