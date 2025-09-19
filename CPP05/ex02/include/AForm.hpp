/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:50:01 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/19 16:04:38 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class	AForm
{
	private:
		const std::string	name;
		const int			grade_sign;
		const int			grade_exec;
		bool				is_signed;
	public:
		AForm( std::string name, int grade_sign, int grade_exec);
		AForm( const AForm& copy );
		virtual ~AForm();

		void				operator=( const AForm& copy );
		const std::string	getName( void ) const;
		int					getGradeSign( void ) const;
		int					getGradeExec( void ) const;
		bool				getIsSigned( void ) const;
		void				beSigned( const Bureaucrat& bur );
		void				checkExec( const Bureaucrat& executor ) const;
		virtual void		execute( const Bureaucrat& executor ) const = 0;

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
		class	FormUnsignedException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);



#endif
