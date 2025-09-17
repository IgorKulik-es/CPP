/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:51:25 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/17 17:51:25 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ): AForm("PresidentialPardonForm", 25, 5), target(copy.getTarget())
{
}

void	PresidentialPardonForm::operator=( const PresidentialPardonForm& copy)
{
	*((AForm *)this) = *((AForm *)&copy);
}


PresidentialPardonForm::~PresidentialPardonForm(){};

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->target);
}

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const
{
	this->checkExec(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

