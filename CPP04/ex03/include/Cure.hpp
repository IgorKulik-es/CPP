/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:25:30 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 14:25:44 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure( const std::string& type );
		Cure( const Cure& copy );
		~Cure();
		void				operator=( const Cure& copy);
		Cure*		clone() const;
		void		use(ICharacter& target);
};

#endif
