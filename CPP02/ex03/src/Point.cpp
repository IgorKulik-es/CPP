/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:29:25 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/05 13:29:25 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point()
{
	x = Fixed(0);
}
Point::Point( const Point& copy )
{
	this->x = copy.getX();
}
Point::~Point()
{
}

const Fixed	Point::getX( void )
{
	return this->x;
}
const Fixed	Point::getY( void )
{
	return this->y;
}
