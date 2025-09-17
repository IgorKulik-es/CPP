/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:41:45 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/17 21:41:45 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;
class AForm;

class	PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm( std::string taget);
		PresidentialPardonForm( const PresidentialPardonForm& copy );
		~PresidentialPardonForm();
		void				operator=( const PresidentialPardonForm& copy );
		std::string			getTarget( void ) const;
		void				execute( const Bureaucrat& executor ) const;
};

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& form);



#endif