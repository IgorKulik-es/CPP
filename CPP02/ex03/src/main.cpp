/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 09:48:01 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/08 17:16:57 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

int main( void )
{
	bool	answer;

	Point	a ( 1.0f, 1.0f );
	Point	b ( 1.0f, 6.0f );
	Point	c ( 6.0f, 1.0f );
	Point	p ( 2.0f, -2.0f );

	answer= bsp(a, b, c, p);
	if (answer)
		std::cout << "true" << std::endl;
	else
		std::cout

	return 0;
}

