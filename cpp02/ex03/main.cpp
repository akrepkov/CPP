/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:40:34 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 16:10:09 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*https://planetcalc.com/8108/*/

#include "Point.hpp"
#include "Fixed.hpp"


int main( void ) {
	const Point a(7,7);
	const Point b(11,1);
	const Point c(2,2);
	const Point point(7,3);
	/*TRUE*/
	std::cout << std::boolalpha << bsp(a, b, c, point) << std::endl;
	const Point a1(-7,7);
	const Point b1(11.7f,1);
	const Point c1(2,2.9f);
	const Point point1(7,3.0f);
	/*FALSE*/
	std::cout << std::boolalpha << bsp(a1, b1, c1, point1)<< std::endl;
	const Point a2(0,0);
	const Point b2(0,0);
	const Point c2(0,0);
	const Point point2(0,0);
	/*FALSE*/
	std::cout << std::boolalpha << bsp(a2, b2, c2, point2)<< std::endl;

	return 0;
}