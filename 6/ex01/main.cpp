/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:06:19 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/08 15:05:08 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
/*Serialize - it’s all about taking something complicated 
and turning it into a flat sequence of 1s and 0s, 
then taking that sequence of 1s and 0s (possibly 
at another place, possibly at another time) 
and reconstructing the original complicated “something.”*/
int main(){
	Data test;
	test.x = 5;
	uintptr_t testS = Serializer::serialize(&test);
	Data* testD = Serializer::deserialize(testS);
	std::cout << &test << std::endl;
	std::cout << testD << std::endl;
	std::cout << testD->x << std::endl;



	return 0;
}


/*WHAT IS REINTERPRET CAST*/
//https://isocpp.org/wiki/faq/serialization



/*Private Constructor: 
By making the constructor private, we prevent users from creating instances 
of the Serializer class. Since the constructor is inaccessible outside the class, 
users cannot instantiate objects of this class.

Static Methods: 

Both serialize and deserialize methods are declared as static. 
This means they belong to the class itself rather than any specific instance of the class. 
Users can call these methods without creating an instance of the Serializer class.*/