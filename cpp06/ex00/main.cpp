/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:09:21 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/08 15:08:07 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://learn.microsoft.com/ru-ru/cpp/cpp/dynamic-cast-operator?view=msvc-170&viewFallbackFrom=vs-2019 dynamic cast upcast
#include <string>
#include <iostream>
#include "ScalarConverter.hpp"
/*статические переменные сохраняют свои значения и не уничтожаются 
даже после выхода из блока, в котором они объявлены. статические члены существуют, 
даже если объекты класса не созданы! Подобно глобальным переменным, они создаются 
при запуске программы и уничтожаются, 
когда программа завершает свое выполнение.Следовательно, статические члены принадлежат классу, 
а не объектам этого класса. Поскольку s_value существует независимо от любых объектов класса, 
то доступ к нему осуществляется напрямую 
через имя класса и оператор разрешения области видимости* (Animal::name)*/


int main(){

	ADD canonical form
	// ScalarConverter::convert("+inf");
	// ScalarConverter::convert("-inf");
	// ScalarConverter::convert("+inff");
	// ScalarConverter::convert("-inff");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("nan");
	// ScalarConverter::convert(nullptr);
	// ScalarConverter::convert("String");
	// ScalarConverter::convert("-1.0f");
	// ScalarConverter::convert("1.01f");
	// ScalarConverter::convert("1.0545");
	// ScalarConverter::convert("-4.2");
	// ScalarConverter::convert("4.2");
	// ScalarConverter::convert("a");
	// ScalarConverter::convert("f");
	ScalarConverter::convert("0");
	ScalarConverter::convert("42.0f");
	// ScalarConverter::convert("-456");
	ScalarConverter::convert("-7897987987897987");
	return 0;
}
/*
	promotions are subsets of a wider range of conversions.

    char -> int: integral promotion
    float -> double: floating point promotion
    int -> char: [narrowing] conversion (not a promotion)
    int -> float: conversion
    const char* -> std::string: conversion


	An implicit cast is a cast that the database server can invoke automatically when it encounters data types that cannot be compared with built-in casts. 

	*/

/*
READ THIS:
https://stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast
dynamic_cast is useful when you don't know what the dynamic type of the object is. It returns a null pointer if the object referred to doesn't contain the type casted to as a base class (when you cast to a reference, a bad_cast exception is thrown in that case).
You can not use dynamic_cast for downcast (casting to a derived class) if the argument type is not polymorphic. 
An "up-cast" (cast to the base class) is always valid with both static_cast and dynamic_cast, and also without any cast

*/

//convert Child to Parent - implicit conversion, static_cast
//Parent to Child - dynamic_cast