/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:39:16 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 17:49:33 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//ADD TESTS
/*In C++, adding const at the end of a function declaration or definition indicates 
that the function is a "const member function". This means that the function promises 
not to modify the state of the object on which it is called. 
*/

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}