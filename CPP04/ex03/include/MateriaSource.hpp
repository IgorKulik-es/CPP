/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:42:29 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 17:55:00 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#define MAX_MATERIA_S 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	inventory[MAX_MATERIA_S];
	public:
		MateriaSource( );
		MateriaSource( const MateriaSource& copy );
		~MateriaSource( );
		void			operator=( const MateriaSource& copy );
		const AMateria*	getMateria( int index ) const;
		void			learnMateria( AMateria* m );
		AMateria*		createMateria( const std::string& type );
};

#endif
