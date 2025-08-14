/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:34:44 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/14 18:23:26 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
	Animal*	zoo[4];

	std::cout << "\nCOPY OPERATORS VERIFICATION\n" << std::endl;

	Dog		dog1;
	Brain	implant;

	for(int i = 0; i < BRAIN_SIZE; i++)
		implant.setIdea("Dog food", i);
	dog1.setBrain(implant);

	Dog	dog_copy(dog1);

	dog_copy.getBrain()->setIdea("Sleep", 0);
	std::cout << "\nOriginal thought: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy thought: " << dog_copy.getBrain()->getIdea(0) << std::endl;
	std::cout << "\nARRAY CREATION\n\n";

	zoo[0] = new Dog();
	zoo[1] = new Dog();
	zoo[2] = new Cat();
	zoo[3] = new Cat();

	for (int i = 0; i < 4; i++)
	{
		std::cout << zoo[i]->getType() << ": ";
		zoo[i]->makeSound();
	}
	for (int i = 0; i < 4; i++)
		delete zoo[i];
	return 0;
}
