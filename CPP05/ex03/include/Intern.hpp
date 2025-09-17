/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:56:28 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/17 21:56:28 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <map>

class	Intern
{
	private:
		AForm*	makeShrubForm( std::string target ) const;
		AForm*	makeRobotForm( std::string target ) const;
		AForm*	makePardonForm( std::string target ) const;
	public:
		Intern();
		Intern( const Intern& copy );
		~Intern();
		void	operator=( const Intern& copy );
		AForm*	makeForm( std::string form_name, std::string target ) const;
};

#endif