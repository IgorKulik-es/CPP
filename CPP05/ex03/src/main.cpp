/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:54:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/22 14:19:24 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	Intern	dave;
	AForm*	form_1;
	AForm*	form_2;

	form_1 = dave.makeForm("robotomy request", "nice shrubery");
	if (form_1)
		std::cout << "Created " << *form_1 << std::endl;
	form_2 = dave.makeForm("wrong_form", "chocolate cake");
	if (form_2)
		std::cout << "Created " << *form_2 << std::endl;
	delete form_1;
	delete form_2;
}
