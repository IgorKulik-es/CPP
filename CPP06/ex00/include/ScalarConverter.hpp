/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:15:27 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/18 12:45:40 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP


# include <iostream>
# include <string>

class	ScalarConverter
{
	private:
		const std::string	name;
		int					grade;
	public:
		ScalarConverter( std::string name, int grade);
		ScalarConverter( const ScalarConverter& copy );
		virtual ~ScalarConverter() = 0;
		void		operator=( const ScalarConverter& copy );
		static void	convert(std::string number);
};

#endif
