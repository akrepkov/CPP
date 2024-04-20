/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:19:35 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/01 13:51:22 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal";
	std::cout << type << " Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << type << " Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a){
	if (this != &a){
		type = a.type;
	}
	std::cout << type << " Assignment operator called" << std::endl;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &a){
	*this = a;
	std::cout << type << " Copy constructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
	return (this->type);
}

void WrongAnimal::makeSound() const{
	std::cout << this->type << " is making an unappropriate sound" << std::endl;
}