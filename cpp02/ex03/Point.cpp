/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:26 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 15:58:06 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(){
	Fixed _x();
	Fixed _y();
}

Point::~Point(){
}

Point& Point::operator=(const Point &a){
	*this = a;
	return (*this);
}

const Fixed &Point::getX(void) const
{
	return(this->_x);
}

const Fixed &Point::getY(void) const
{
	return(this->_y);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	float ABx = b.getX().toFloat() - a.getX().toFloat();
	float ABy = b.getY().toFloat() - a.getY().toFloat();
	float APx = point.getX().toFloat() - a.getX().toFloat();
	float APy = point.getY().toFloat() - a.getY().toFloat();
	float BCx = c.getX().toFloat() - b.getX().toFloat();
	float BCy = c.getY().toFloat() - b.getY().toFloat();
	float BPx = point.getX().toFloat() - b.getX().toFloat();
	float BPy = point.getY().toFloat() - b.getY().toFloat();
	float CAx = a.getX().toFloat() - c.getX().toFloat();
	float CAy = a.getY().toFloat() - c.getY().toFloat();
	float CPx = point.getX().toFloat() - c.getX().toFloat();
	float CPy = point.getY().toFloat() - c.getY().toFloat();
	float AP_pos = ABx * APy - ABy * APx;
	float BP_pos = BCx * BPy - BCy * BPx;
	float CP_pos = CAx * CPy - CAy * CPx;
	if ((AP_pos > 0 && BP_pos > 0 && CP_pos > 0) || (AP_pos < 0 && BP_pos < 0 && CP_pos < 0) )
		return true;
	else
		return false;
}

/*To check if the point is inside we need to check the sides:
ABx it's x position of the vector AB (Bx - Ax)
ABy - y position of the vector AB (By - Ay)
Multiplication for 3d vectors is calculated this way:
A * B = AyBz - AzBy, AzBx - AxBz, AxBy - AyBx
Due to the fact that our triangle is 2D, z is equals to 0 and
cross products (z-coordinate) equals to AxBy - AyBx.
In our case it's:
float AP_pos = ABx * APy - ABy * APx.
and because of Anti-commutative property: ab = -ba,
if all AP_pos and BP_pos and CP_pos are positive (or all together negative) - then point is inside;
if one of them is equal 0 - the point is on the side of triangle
If 1 value has different sign - the point is outside the triangle.
*/