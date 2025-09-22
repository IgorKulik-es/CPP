/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:51:25 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/22 13:42:47 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( const std::string& name, int grade_sign, int grade_exec): name(name), grade_sign(grade_sign), grade_exec(grade_exec)
{
	if (grade_sign < GRADE_HIGHEST || grade_exec < GRADE_HIGHEST)
		throw GradeTooHighException();
	if (grade_sign > GRADE_LOWEST || grade_sign > GRADE_LOWEST)
		throw GradeTooLowException();
	is_signed = false;
}

AForm::AForm( const AForm& copy): name(copy.getName()), grade_sign(copy.getGradeSign()), grade_exec(copy.getGradeExec())
{
	*this = copy;
}

void	AForm::operator=( const AForm& copy)
{
	this->is_signed = copy.getIsSigned();
}

std::ostream&	operator<<(std::ostream& os, const AForm& AForm)
{
	os << AForm.getName() << ", grade to sign: " << AForm.getGradeSign();
	os << ", grade to execute: " << AForm.getGradeExec();
	if (AForm.getIsSigned())
		os << ". It is signed.";
	else
		os << ". It is unsigned.";
	return (os);
}

AForm::~AForm(){};

const std::string	AForm::getName( void ) const
{
	return (this->name);
}

int	AForm::getGradeSign( void ) const
{
	return (this->grade_sign);
}

int	AForm::getGradeExec( void ) const
{
	return (this->grade_exec);
}

bool	AForm::getIsSigned( void ) const
{
	return (this->is_signed);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "AForm::GradeTooHighException";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "AForm::GradeTooLowException";
}

const char*	AForm::FormUnsignedException::what() const throw()
{
	return "AForm::FormUnsignedException";
}

void	AForm::beSigned( const Bureaucrat& bur)
{
	if (bur.getGrade() > this->grade_sign)
		throw GradeTooLowException();
	this->is_signed = true;
}

void	AForm::checkExec( const Bureaucrat& executor ) const
{
	if (this->is_signed == false)
		throw FormUnsignedException();
	if (executor.getGrade() > this->grade_exec)
		throw GradeTooLowException();
}
