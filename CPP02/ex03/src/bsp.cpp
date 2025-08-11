/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:27:42 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/11 16:57:33 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

//function calculates laterality of the thre vectors that form the triangle
//for debug use std::cout << side_ab << " " << side_ca << " " << side_bc << std::endl;

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	side_ab;
	Fixed	side_ca;
	Fixed	side_bc;

	side_ab = ((a.getX() - b.getX()) * (point.getY() - b.getY()))
			- ((a.getY() - b.getY()) * (point.getX() - b.getX()));
	side_bc = ((b.getX() - c.getX()) * (point.getY() - c.getY()))
			- ((b.getY() - c.getY()) * (point.getX() - c.getX()));
	side_ca = ((c.getX() - a.getX()) * (point.getY() - a.getY()))
			- ((c.getY() - a.getY()) * (point.getX() - a.getX()));
	if ((side_ab == 0) || (side_bc == 0) || (side_ca == 0))
		return false;
	if (((side_ab < 0) != (side_ca < 0)))
		return false;
	return ((side_bc < 0) == (side_ab < 0));
}
