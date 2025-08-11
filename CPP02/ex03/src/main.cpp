/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 09:48:01 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/11 17:00:23 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

int main( void )
{
	{
	bool	answer;

	Point	a ( -2.0f, 5.0f );
	Point	b ( 3.0f, 5.0f );
	Point	c ( 0.0f, 0.0f );
	Point	p ( 0.0f, 4.0f );

	answer= bsp(a, b, c, p);
	if (answer)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	}
	{
	bool	answer;

	Point	a ( -2.0f, 5.0f );
	Point	b ( 3.0f, 5.0f );
	Point	c ( 0.0f, 0.0f );
	Point	p ( 0.0f, 6.0f );

	answer= bsp(a, b, c, p);
	if (answer)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	}
	{
	bool	answer;

	Point	a ( -1.0f, 0.0f );
	Point	b ( 5.0f, 3.0f );
	Point	c ( 5.0f, -3.0f );
	Point	p ( 4.9f, 0.0f );

	answer= bsp(a, b, c, p);
	if (answer)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	}
	return 0;
}

