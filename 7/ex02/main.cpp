/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:20:26 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/17 15:08:10 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 7 //make smaller for test

void testing(Array<int> tmp){
    for (int i = 0; i < MAX_VAL; i++){
		std::cout << "Test " << tmp[i] << std::endl;
    }
	try {
		std::cout << "Test " << tmp[1000] << std::endl;
	} catch(std::exception& e){
		std::cout << "Out of scope" << std::endl;
	}
	try { //check this again
		Array<int> test(0);
		std::cout << "Legth - 0 " << test[0] << std::endl;
	} catch(std::exception& e){
		std::cout << "Array doesn't exist" << std::endl;
	}
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
		//std::cout << "Main check " << numbers[i] << "   " << mirror[i] << std::endl;
    }
    //SCOPE
    {
        Array<int> tmp = numbers; //check = operator
        Array<int> test(tmp); //check copy constructor
		testing(test);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
		//std::cout << numbers[i] << std::endl;
    }
    delete [] mirror;//

    return 0;
}