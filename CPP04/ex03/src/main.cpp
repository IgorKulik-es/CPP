/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:34:44 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 18:17:58 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"
#include "../include/Ice.hpp"
#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"

int main()
{
	{
	Character		elf("Arwen");
	Character		goblin("The Great Goblin");
	Character		wizard("Radagast");
	AMateria		*ice = new Ice();
	AMateria		*cure = new Cure();
	IMateriaSource	*source = new MateriaSource();



 	source->learnMateria(ice);
	source->learnMateria(cure);

	wizard.equip(source->createMateria("ice"));
	wizard.use(0, goblin);
	goblin.equip(source->createMateria("cure"));
	goblin.use(0, wizard);

	elf.equip(source->createMateria("cure"));
	elf = wizard;
	elf.use(0, goblin);

	delete source;
	}
	{
	IMateriaSource*	src = new MateriaSource();
	ICharacter*		me = new Character("me");
	AMateria*		tmp;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	}
	return 0;
}
