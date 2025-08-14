/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:34:44 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 18:20:55 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	const Animal*		meta = new Animal();
	const Animal*		j = new Dog();
	const Animal*		i = new Cat();
	const WrongAnimal*	beast = new WrongAnimal();
	const WrongAnimal*	tom = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << i->getType() << ": ";
	i->makeSound(); //will output the cat sound!
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	std::cout << beast->getType() << ": ";
	beast->makeSound();
	std::cout << tom->getType() << ": ";
	tom->makeSound();

	delete meta;
	delete i;
	delete j;
	delete beast;
	delete tom;

	return 0;
}
