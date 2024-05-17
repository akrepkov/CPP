/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:07:00 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/15 11:44:24 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// Base::Base() {
// }

Base::~Base() {
}

// Base& Base::operator=(const Base& copy) {
// 	if (this != &copy) {
// 	}
//     return *this;
// }

// Base::Base(const Base& copy) {
// 	*this = copy;
// }

Base* generate(void){
	srand(time(NULL)); //what exactly does it do?
	int target = std::rand() % 3;
	if (target == 0)
	{
		std::cout << "Instanciating A" << std::endl;
		return new A;
	}
	else if (target == 1)
	{
		std::cout << "Instanciating B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Instanciating C" << std::endl;
		return new C;
	}
}
void identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
		std::cout<< "Identification through the pointer: " << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout<< "Identification through the pointer: " << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout<< "Identification through the pointer: " << "C" << std::endl;
	else
		std::cout<< "Error" << std::endl;
}
void identify(Base& p){
	try{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Identification through the reference: " << "A" << std::endl;
		(void)a;
	} catch (std::bad_cast& e){};
	try{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Identification through the reference: " << "B" << std::endl;
		(void)b;
	} catch (std::bad_cast& e){};
	try{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Identification through the reference: " << "C" << std::endl;
		(void)c;
	} catch (std::bad_cast& e){};
/*Поскольку в языке C++ не существует «нулевой ссылки», 
то dynamic_cast не может возвратить «нулевую ссылку» при сбое. */
}