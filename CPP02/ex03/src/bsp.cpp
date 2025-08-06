/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:27:42 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/06 19:29:15 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	side_ab;
	Fixed	side_ac;
	Fixed	side_bc;

	side_ab = (a.getX() - b.getX()) * (point.getX() - b.getX())
			- (a.getY() - b.getY()) * (point.getY() - b.getY());
	side_ac = (a.getX() - c.getX()) * (point.getX() - c.getX())
			- (a.getY() - c.getY()) * (point.getY() - c.getY());
	side_bc = (b.getX() - c.getX()) * (point.getX() - c.getX())
			- (b.getY() - c.getY()) * (point.getY() - c.getY());
	std::cout << side_ab << " " << side_ac << " " << side_bc << std::endl;
	return true;
}
