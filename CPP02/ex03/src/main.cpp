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

	Point	a ( 0.0f, 5.0f );
	Point	b ( 3.0f, 0.0f );
	Point	c ( 0.0f, 0.0f );
	Point	p ( -3.0f, 9.0f );

	answer= bsp(a, b, c, p);
	if (answer)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	return 0;
}

