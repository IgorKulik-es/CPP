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

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	dave("Dave", 2);
	Form		form_1("Credit score assesment form", 50, 30);

	std::cout << "Instantiated: " << dave << std::endl;
	std::cout << "Instantiated: " << form_1 << std::endl;
	try
	{
		Form	form_2("Some other form", 0, 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	dave.signForm(form_1);

	Bureaucrat	guy("Philip J. Fry", 90);
	Form		form_2("Spaceship parts requistion form", 70, 30);

	guy.signForm(form_2);
	return (0);
}