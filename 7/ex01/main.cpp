/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:46:36 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/16 13:55:09 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

class Test {
	public:
		int _test;
		Test(int test): _test(test){}
		~Test(){};
};

std::ostream& operator<<(std::ostream &out, const Test &test){
	out << test._test;
	return out;
}

int main(){
	std::cout << "Class: 1 2 3" << std::endl;
	Test testClass[3] = {Test(1), Test(2), Test(3)};
	iter(testClass, 3, printArray<Test>);

	std::cout << "Int: 1,9,2,7,5" << std::endl;
	int len = 5;
	int *array = new int[len] {1,9,2,7,5};
	iter(array, len, printArray<int>);
	delete[] array;

	std::cout << "Double: 8.3, 2.9, 7.1, 3.9" << std::endl;
	double testD[] = { 8.3, 2.9, 7.1, 3.9 };
	iter(testD, 4, printArray<double>);

	std::cout << "Float: 8.3, 2.9, 7.1, 3.9" << std::endl;
	float testF[] = { 8.3f, 2.9f, 7.1f, 3.9f };
	iter(testF, 4, printArray<float>);

	std::cout << "Char: 'a', 'b', 'c', 'd'" << std::endl;
	char arrC[4] = { 'a', 'b', 'c', 'd'};
	iter(arrC, 4, printArray<char>);

	std::cout << "Std::string: Hello, World" << std::endl;
	std::string *arr2 = new std::string[2] {"Hello", "World"};
	iter(arr2, 2, printArray<std::string>);
	delete[] arr2;
	return 0;
}
