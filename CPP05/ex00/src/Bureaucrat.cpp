/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:46:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/22 13:28:03 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string& name, int grade ): name(name)
{
	if (grade < GRADE_HIGHEST)
		throw GradeTooHighException();
	if (grade > GRADE_LOWEST)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ): name(copy.getName())
{
	*this = copy;
}

void	Bureaucrat::operator=( const Bureaucrat& copy )
{
	this->grade = copy.getGrade();
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bur )
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (os);
}

Bureaucrat::~Bureaucrat(){};

const std::string	Bureaucrat::getName( void ) const
{
	return (this->name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

void	Bureaucrat::IncrementGrade( void )
{
	if (this->grade == GRADE_HIGHEST)
		throw GradeTooHighException();
	(this->grade)--;
}

void	Bureaucrat::DecrementGrade( void )
{
	if (this->grade == GRADE_LOWEST)
		throw GradeTooLowException();
	(this->grade)++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHighException";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLowException";
}
