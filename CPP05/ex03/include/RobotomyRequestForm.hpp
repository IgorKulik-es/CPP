/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:00:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/22 13:46:02 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class Bureaucrat;
class AForm;

class	RobotomyRequestForm : public AForm
{
	private:
		const std::string	target;
	public:
		RobotomyRequestForm( const std::string& taget );
		RobotomyRequestForm( const RobotomyRequestForm& copy );
		~RobotomyRequestForm();
		void				operator=( const RobotomyRequestForm& copy );
		std::string			getTarget( void ) const;
		void				execute( const Bureaucrat& executor ) const;
};

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& form);



#endif
