/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:51:25 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/22 13:44:21 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

static void	printTree(std::ostream& os);

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ): AForm("ShrubberyCreationForm", 145, 137), target(copy.getTarget())
{

}

void	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy)
{
	*((AForm *)this) = *((AForm *)&copy);
}


ShrubberyCreationForm::~ShrubberyCreationForm(){};

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
{
	std::ofstream	file;
	std::string		file_name;

	this->checkExec(executor);
	file_name = this->target;
	file_name.append("_shrubbery");
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	file.open(file_name.c_str(), std::ios::out | std::ios::trunc);
	for (int i = 0; i < 5; i++)
		printTree(file);
	file.close();
}


static void	printTree(std::ostream& os)
{
	os << "       ###" << std::endl;
	os << "      #o###" << std::endl;
	os << "    #####o###" << std::endl;
	os << "   #o###|#/###" << std::endl;
	os << "    ####|/#o#" << std::endl;
	os << "     # }|{  #" << std::endl;
	os << "       }|{" << std::endl << std::endl;
}
