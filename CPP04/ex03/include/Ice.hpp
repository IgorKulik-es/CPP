/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:50:07 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 17:54:32 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice( );
		Ice( const Ice& copy );
		~Ice();
		void	operator=( const Ice& copy);
		Ice*	clone() const;
		void	use(ICharacter& target);
};

#endif
