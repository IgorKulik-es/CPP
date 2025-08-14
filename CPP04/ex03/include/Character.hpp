/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:40:11 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 14:59:57 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#define MAX_MATERIAS 4

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*inventory[4];
	public:
		Character( const std::string& name);
		Character ( const Character& copy );
		~Character();
		void	operator=( const Character& copy);
		const std::string& getName() const;
		void	Character::setName( const std::string& name);
		const AMateria*	getMateria( int index) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
