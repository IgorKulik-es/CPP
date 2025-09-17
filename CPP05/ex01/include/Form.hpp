/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:59:04 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/15 11:59:04 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <sstream>

class Bureaucrat;

class	Form
{
	private:
		const std::string	name;
		const int			grade_sign;
		const int			grade_exec;
		bool				is_signed;
	public:
		Form( std::string name, int grade_sign, int grade_exec);
		Form( const Form& copy );
		~Form();
		
		void				operator=( const Form& copy );
		const std::string	getName( void ) const;
		int					getGradeSign( void ) const;
		int					getGradeExec( void ) const;
		bool				getIsSigned( void ) const;
		void				beSigned( const Bureaucrat& bur);

		class	GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);



#endif