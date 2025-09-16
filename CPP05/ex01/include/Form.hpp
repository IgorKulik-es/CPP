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
# include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	name;
		int					grade;
	public:
		Form( std::string name, int grade);
		Form( const Form& copy );
		~Form();
		
		void				operator=( const Form& copy );
		const std::string	getName( void ) const;
		int					getGrade( void ) const;
		void				IncrementGrade( void );
		void				DecrementGrade( void );

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