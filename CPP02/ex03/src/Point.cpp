/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:29:25 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/06 18:29:52 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
}
Point::Point( const Point& copy ): x(copy.getX()), y(copy.getY())
{
}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y))
{
}
Point::~Point()
{
}

const Fixed	Point::getX( void ) const
{
	return this->x;
}
const Fixed	Point::getY( void ) const
{
	return this->y;
}

void Point::operator=( const Point& copy)
{
	(void)copy;
}
