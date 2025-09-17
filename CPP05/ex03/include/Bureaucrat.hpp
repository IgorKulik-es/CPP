/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:39:14 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/13 16:39:14 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define GRADE_HIGHEST 1
# define GRADE_LOWEST 150

# include <iostream>
# include <string>
# include <sstream>

class	AForm;

class	Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat( std::string name, int grade);
		Bureaucrat( const Bureaucrat& copy );
		~Bureaucrat();
		
		void				operator=( const Bureaucrat& copy );
		const std::string	getName( void ) const;
		int					getGrade( void ) const;
		void				IncrementGrade( void );
		void				DecrementGrade( void );
		void				signForm( AForm& form) const;
		void				executeForm( const AForm& form ) const;

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

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bur);



#endif