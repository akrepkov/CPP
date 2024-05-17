/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:24:50 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/16 13:54:48 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_hpp
#define iter_hpp

/*Поскольку тип аргумента функции, передаваемый в тип T, может быть классом, 
а классы не рекомендуется передавать по значению, 
то лучше сделать параметры и возвращаемое значение нашего шаблона функции константными ссылками*/

template <typename T1, typename F>
void iter(T1* array,int length, F foo){
	for (int i = 0; i < length; i++){
		foo(array[i]);
	}
} //this way can accept functors(an object that can be called as if it were an ordinary function)
//and lambdas (inline defined functions)

template <typename T>
void iter(T* array, int length,void (*function)(const T&)){
	for (int i = 0; i < length; i++){
		function(array[i]);
	}
}

/*When you print a float or double value using std::cout, 
the default output format does not include the suffix f 
that is used in code to denote a float literal. 
The f suffix is purely a syntactical indicator to tell 
the compiler that a literal is of type float, 
but it is not part of the value itself.*/

template <typename T>
void printArray(T n){
	std::cout << n << std::endl;
}

#endif