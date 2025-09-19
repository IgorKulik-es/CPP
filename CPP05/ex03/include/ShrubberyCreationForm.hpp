/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:53:56 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/19 16:00:43 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>
# include <fstream>

class Bureaucrat;
class AForm;

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm( std::string taget);
		ShrubberyCreationForm( const ShrubberyCreationForm& copy );
		~ShrubberyCreationForm();
		void				operator=( const ShrubberyCreationForm& copy );
		std::string			getTarget( void ) const;
		void				execute( const Bureaucrat& executor ) const;
};

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& form);



#endif
