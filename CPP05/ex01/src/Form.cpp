/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:40:50 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/17 09:40:50 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( std::string name, int grade_sign, int grade_exec): name(name), grade_sign(grade_sign), grade_exec(grade_exec)
{
	if (grade_sign < GRADE_HIGHEST || grade_exec < GRADE_HIGHEST)
		throw GradeTooHighException();
	if (grade_sign > GRADE_LOWEST || grade_sign > GRADE_LOWEST)
		throw GradeTooLowException();
	is_signed = false;
}

Form::Form( const Form& copy): name(copy.getName()), grade_sign(copy.getGradeSign()), grade_exec(copy.getGradeExec())
{
	*this = copy;
}

void	Form::operator=( const Form& copy)
{
	this->is_signed = copy.getIsSigned();
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ", grade to sign: " << form.getGradeSign();
	os << ", form grade to execute: " << form.getGradeExec();
	if (form.getIsSigned())
		os << ". It is signed.";
	else
		os << ". It is unsigned.";
	return (os);
}

Form::~Form(){};

const std::string	Form::getName( void ) const
{
	return (this->name);
}

int	Form::getGradeSign( void ) const
{
	return (this->grade_sign);
}

int	Form::getGradeExec( void ) const
{
	return (this->grade_exec);
}

bool	Form::getIsSigned( void ) const
{
	return (this->is_signed);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHighException";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLowException";
}

void	Form::beSigned( const Bureaucrat& bur)
{
	if (bur.getGrade() > this->grade_sign)
		throw GradeTooLowException();
	this->is_signed = true;
}