/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:11:12 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/08 14:26:47 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <regex>
#include <string>
#include <limits>

//#define INF ((unsigned) ~0)

int lengthInt(unsigned i){
	return i > 0 ? (int)(log10((double)i) + 1 ): 1; 
	/*
	1. convert i to double to make sure that we don't loose anything
	2. how many times we need to multiply 10 to get our i
	3. cast to int to remove fractional part
	4. add 1 cause it was subtracted during calculations*/
}


std::string findtype(const std::string& a) {
    if (a.length() == 1)
	{
		if (a[0] >= '0' && a[0] <= '9')
			return "int";
        return "char";
	}
	std::regex int_pattern("(-?\\d+)");
	if (regex_match(a, int_pattern))
		return "int";
	std::regex float_pattern("(-?\\d+)\\.(\\d+)f");
	if (regex_match(a, float_pattern))
		return "float";
	std::regex double_pattern("(-?\\d+)\\.(\\d+)");
	if (regex_match(a, double_pattern))
		return "double";
    return "unknown";
}
void ScalarConverter::convert(std::nullptr_t) {
    std::cout << "nullptr was passed" << std::endl;
}

void ScalarConverter::convert(const std::string& literal){
	std::cout << "\033[2;33;20mOriginal string: " << literal << "\033[0m\t\t" << std::endl;
	if (findtype(literal) == "char"){
		char c = literal[0];
		std::cout << "Char: " << c << std::endl;
		std::cout << "Char: to int " << static_cast<int>(c) << std::endl;
		std::cout << "Char: to float " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "Char: to double " << static_cast<double>(c) << ".00" << std::endl;
	} 
	else if (findtype(literal) == "int"){
		try{
			int a = (std::stoi(literal));
		std::cout << "Int: " << literal << std::endl;
		if (isprint(a))
			std::cout << "Int: to char " << static_cast<char>(a) << std::endl;
		else
			std::cout << "Int: to char: Impossible to cast" << std::endl;
		std::cout << "Int: to float " << static_cast<float>(a) << ".0f" << std::endl; 
		std::cout << "Int: to double " << static_cast<double>(a) << ".00" << std::endl;
		} catch (std::exception &e){
			std::cout << "Out of range" << std::endl;
		}
	}
	else if (findtype(literal) == "float"){
		float a = (std::stof(literal));
		std::cout << "Float: " << literal << std::endl;
		if (isprint(a))
			std::cout << "Float: to char " << static_cast<char>(a) << std::endl; //RIGHT??????????????
		else
			std::cout << "Float: to char: Impossible to cast" << std::endl;
		std::cout << "Float: to int " << static_cast<int>(a) << std::endl;
		if (std::stof(literal) == std::stoi(literal))
			std::cout << "Float: to double " << static_cast<double>(a) << ".00" << std::endl;
		else
			std::cout << "Float: to double " << static_cast<double>(a) << std::endl;
	}
	else if (findtype(literal) == "double"){
		double a = (std::stod(literal));
		std::cout << "Double: " << a << std::endl;
		if (isprint(a))
			std::cout << "Double: to char " << static_cast<char>(a) << std::endl; //RIGHT??????????????
		else
			std::cout << "Double: to char: Impossible to cast" << std::endl;
		std::cout << "Double: to int " << static_cast<int>(a) << std::endl;
		std::cout << "Double: to float " << static_cast<float>(a) << "f" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff"){
		double inf = std::numeric_limits<double>::infinity();
		std::cout << literal << " : to char " << "Impossible to cast" << std::endl;
		std::cout << literal << " : to int " << "Impossible to cast" << std::endl;
		std::cout << literal << " : to float " << static_cast<float>(inf) << "f" << std::endl;
		std::cout << literal << " : to double " << static_cast<double>(inf) << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff"){
		double inf = -std::numeric_limits<double>::infinity();
		std::cout << literal << " : to char " << "Impossible to cast" << std::endl;
		std::cout << literal << " : to int " << "Impossible to cast" << std::endl;
		std::cout << literal << " : to float " << static_cast<float>(inf) << "f"  << std::endl;
		std::cout << literal << " : to double " << static_cast<double>(inf) << std::endl;
	}
	else if (literal == "nan" || literal == "nanf"){
		std::cout << literal << " : to char " << "Impossible to cast" << std::endl;
		std::cout << literal << " : to int " << "Impossible to cast" << std::endl;
		std::cout << literal << " : to float " << std::numeric_limits<float>::quiet_NaN() << "f"  << std::endl;
		std::cout << literal << " : to double " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	}
/*NaN (Not a Number) represents a value that is undefined or unrepresentable according to the floating-point standard. 
In C++, you can obtain NaN using the std::numeric_limits<T>::quiet_NaN() function*/
	else
		std::cout << "Error" << std::endl;
READ MORE ABOUT what cast to use in What situation

}
//std::floor(a)) //check if a has fractional part 

/*Promotion casts involve the automatic conversion of lower-ranked types 
to higher-ranked types in expressions.
Here's a general hierarchy of types from lower rank to higher rank in C++:

    bool
    char, signed char, unsigned char, short, unsigned short
    int, unsigned int
    long, unsigned long
    long long, unsigned long long
    float
    double
    long double
	
Implicit cast is a cast that the database server can invoke automatically 
when it encounters data types that cannot be compared with built-in casts.
short s = 100;
int i = s;

int num = 10;
double d = num;

An explicit cast is a cast that you must specifically invoke
double d = 3.14;
int i = static_cast<int>(d);*/