/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:00:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/17 21:00:26 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class Bureaucrat;
class AForm;

class	RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm( std::string taget);
		RobotomyRequestForm( const RobotomyRequestForm& copy );
		~RobotomyRequestForm();
		void				operator=( const RobotomyRequestForm& copy );
		std::string			getTarget( void ) const;
		void				execute( const Bureaucrat& executor ) const;
};

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& form);



#endif