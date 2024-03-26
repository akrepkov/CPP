/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:16:14 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 17:30:40 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void test(){
	Fixed a;
	Fixed const b(5);
	std::cout << a << " = " << b  << " is " <<std::boolalpha << (a == b) << std::endl;
	std::cout << a << " != " << b  << " is " <<std::boolalpha << (a != b) << std::endl;
	a = 5;
	if (a > b)
		std::cout << "a > b: " << a << " > " << b << std::endl;
	else if (a == b)
		std::cout << "a = b: " << a << " = " << b << std::endl;
	else
		std::cout << "a < b: " << a << " < " << b << std::endl;
	a = 3;
	std::cout << "In the pair a and b min is " << Fixed::min(a,b) << " and max is " << Fixed::max(a,b) << std::endl;
	std::cout << b << " / " << a  << " is " << (b/a) << std::endl;

}

int main( void ) {
	// test();
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}