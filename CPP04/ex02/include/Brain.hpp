/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:10:23 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/13 19:23:44 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
#define BRAIN_HPP
#define BRAIN_SIZE 100

#include <iostream>

class Brain
{
	protected:
		std::string	ideas[100];
	public:
		Brain( );
		Brain( Brain& copy );
		~Brain();
		void		operator=(Brain& copy);
		std::string	getIdea( int index ) const;
		void		setIdea( const std::string& idea, int index);
};

#endif
