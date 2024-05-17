/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:20:24 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/17 14:55:03 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef array_hpp
#define array_hpp

template <typename T>
class Array{
	private:
		T *_temp;
		unsigned int _n;
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& copy);
		Array& operator=(const Array& copy);
		T& operator[](unsigned int index);//The Subscript or Array Index Operator 
		unsigned int size() const;

};

template <typename T>
Array<T>::Array() :_n(0){
	_temp = new Array<T>(); //need empty array
}
template <typename T>
Array<T>::Array(unsigned int n){
	_temp = new T[n];
	for (unsigned int i = 0; i < n;i++){
		_temp[i] = T();
		//std::cout << "Constructor " << _temp[i] << std::endl;
	}
	_n = n;
}

template <typename T>
Array<T>::~Array(){
	delete[] _temp;
}

template <typename T>
Array<T>::Array(const Array& copy) {
	_n = copy._n;
	_temp = new T[copy._n];
	if (copy._temp) {
		for (unsigned int i = 0; i < copy._n; i++)
			_temp[i] = copy._temp[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy) {
	delete[] this;
	_n = copy._n;
	_temp = new T[copy._n];
	if (copy._temp) {
		for (unsigned int i = 0; i < copy._n; i++)
			_temp[i] = copy._yemp[i];
	}
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= _n || index < 0){
		throw std::out_of_range("Wrong index)");
	}
	return _temp[index];
}


template <typename T>
unsigned int Array<T>::size() const{
	//std::cout << _n << std::endl;
	return _n;
}
#endif

/*#pragma once

namespace space {

template <typename Type>
class Something {
public:
    void some_interface();
};

} // namespace space

#include "Something.ipp"

Something.ipp

#pragma once

namespace space {

template <typename Type>
void Something<Type>::some_interface() {
    // the implementation
}

} // namespace space
*/