
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern( const Intern& copy)
{
	(void)copy;
}

void	Intern::operator=( const Intern& copy)
{
	(void)copy;
}

Intern::~Intern(){};

AForm*	Intern::makeShrubForm( std::string target ) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotForm( std::string target ) const
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePardonForm( std::string target ) const
{
	return (new PresidentialPardonForm(target));
}
AForm*	Intern::makeForm( std::string form_name, std::string target ) const
{
	AForm*	result;
	AForm* (Intern::*makers[3])(std::string) const = {&Intern::makeShrubForm, &Intern::makeRobotForm, &Intern::makePardonForm};
	std::string	maker_names[3] = {"shrubery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (maker_names[i] == form_name)
		{
			result = (this->*makers[i])(target);
			std::cout << "Intern creates " << *result << std::endl;
			return (result);
		}
	}
	std::cerr << "Form " << form_name << " not found." << std::endl;
	return (0);
}