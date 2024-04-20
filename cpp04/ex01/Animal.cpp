/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:19:35 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/06 18:12:41 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	this->type = "Animal";
	std::cout << "\033[2;20;40m" << type << " Constructor called\033[0m\t\t" << std::endl;
}

Animal::~Animal(){
	std::cout << "\033[2;20;40m" <<  type << " Destructor called\033[0m\t\t" << std::endl;
}

Animal& Animal::operator=(const Animal &a){
	std::cout << "\033[2;20;40m" <<  type << " Assignment operator called\033[0m\t\t" << std::endl;
	if (this != &a){
		type = a.type; /*при работе с классами, в которых динамически выделяется память, 
		почленное (поверхностное) копирование может вызывать проблемы! 
		Это связано с тем, что при поверхностном копировании указателя 
		копируется только адрес указателя — 
		никаких действий по содержимому адреса указателя не предпринимается. */
	}
	return (*this);
}

Animal::Animal(const Animal &a){
	*this = a;
	std::cout << "\033[2;20;40m" <<  type << " Copy constructor called\033[0m\t\t" << std::endl;
}

std::string Animal::getType() const{
	return (this->type);
}

void Animal::makeSound() const{
	std::cout << this->type << " is making an appropriate sound" << std::endl;
}