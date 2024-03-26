/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:37:19 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 16:01:59 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include "Fixed.hpp"

class Point: public Fixed{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) {}
		Point& operator=(const Point &a);
		~Point();
		const Fixed &getX()const;
		const Fixed &getY()const;
};

	bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
