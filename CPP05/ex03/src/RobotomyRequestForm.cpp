/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:51:25 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/22 13:44:07 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ): AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ): AForm("RobotomyRequestForm", 72, 45), target(copy.getTarget())
{

}

void	RobotomyRequestForm::operator=( const RobotomyRequestForm& copy)
{
	*((AForm *)this) = *((AForm *)&copy);
}


RobotomyRequestForm::~RobotomyRequestForm(){};

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->target);
}

void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
	bool	rob_success;

	this->checkExec(executor);
	srand(time(0));
	std::cout << "* DRILLING NOIZES *" << std::endl;
	rob_success = rand() % 2;
	if (rob_success)
		std::cout << "Robotomizing: " << this->target << " has gone successfully." << std::endl;
	else
		std::cout << "Robotomizing: " << this->target << " failed." << std::endl;
}

