/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:24:50 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/15 11:25:10 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef whatever_hpp
#define whatever_hpp

/*Поскольку тип аргумента функции, передаваемый в тип T, может быть классом, 
а классы не рекомендуется передавать по значению, 
то лучше сделать параметры и возвращаемое значение нашего шаблона функции константными ссылками*/

template <typename T>
const T& max(const T& a, const T& b){
	return (a > b) ? a : b;
}

template <typename T>
const T& min(const T& a, const T& b){
	return (a < b) ? a : b;
}

template <typename T>
void swap( T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

#endif