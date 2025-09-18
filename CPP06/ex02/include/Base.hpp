/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:09:20 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/18 19:20:40 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>

class	Base
{
	public:
		virtual ~Base() = 0;
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
