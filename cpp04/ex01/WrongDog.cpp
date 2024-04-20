/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:19:35 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 15:26:27 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog(){
	this->type = "WrongDog";
	std::cout << type << " Constructor called" << std::endl;
}

WrongDog::~WrongDog(){
	std::cout << type << " Destructor called" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog &a){
	std::cout << type << " Assignment operator called" << std::endl;
	if (this != &a){
		type = a.type;
	}
	return (*this);
}

WrongDog::WrongDog(const WrongDog &a): WrongAnimal(a){
	std::cout << type << " Copy constructor called" << std::endl;
	*this = a;
}

std::string WrongDog::getType() const{
	return (this->type);
}

void WrongDog::makeSound() const{
	std::cout << this->type << " is dancing without any sound" << std::endl;
}