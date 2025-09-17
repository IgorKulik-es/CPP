/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:54:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/14 12:54:26 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	roger("Roger the Shrubber", 70);
	Bureaucrat	dr_robotnik("Roboticizer", 45);
	Bureaucrat	president("President", 1);
	AForm*		form_1 = new ShrubberyCreationForm("Nice_and_not_too_expensive");
	AForm*		form_2 = new RobotomyRequestForm("Robobrain_tranplant");
	AForm*		form_3 = new PresidentialPardonForm("Arthur Dent");

	std::cout << "Instantiated: " << roger << std::endl;
	std::cout << "Instantiated: " << dr_robotnik << std::endl;
	std::cout << "Instantiated: " << president << std::endl;
	std::cout << "Instantiated: " << *form_1 << std::endl;
	std::cout << "Instantiated: " << *form_2 << std::endl;
	std::cout << "Instantiated: " << *form_3 << std::endl;

	roger.executeForm(*form_1);
	roger.signForm(*form_1);
	roger.executeForm(*form_1);

	dr_robotnik.signForm(*form_2);
	roger.executeForm(*form_2);
	dr_robotnik.executeForm(*form_2);

	president.signForm(*form_3);
	president.executeForm(*form_3);

	delete form_1;
	delete form_2;
	delete form_3;
}