/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:06:07 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/15 12:36:03 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

// class Test {
// 	public:
// 		int _test;
// 		Test(int test): _test(test){}
// 		Test(Test &a) : _test(a._test){}
// 		~Test(){};
// };

// bool operator<(const Test &d1, const Test &d2)
// {
// 	return (d1._test < d2._test);
// }
// bool operator>(const Test &d1, const Test &d2)
// {
// 	return (d1._test > d2._test);
// }
// std::ostream& operator<<(std::ostream &out, const Test &test){
// 	out << test._test;
// 	return out;
// }

int main(){
	// Test seven(7);
	// Test two(2);
	// std::cout << "max( seven, two ) = " << ::max(seven, two) << std::endl;
	// std::cout << "min( seven, two ) = " << ::min(seven, two) << std::endl;
	// std::cout << "seven = " << seven << ", two = " << two << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;	
}