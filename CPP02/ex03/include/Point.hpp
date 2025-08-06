/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:24:57 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/06 19:31:37 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float x, const float y);
		Point( const Point& copy );
		~Point();
		void	operator=(const Point& copy);
		const Fixed	getX( void ) const;
		const Fixed	getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
