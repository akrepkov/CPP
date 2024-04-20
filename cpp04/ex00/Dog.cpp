/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:19:35 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 15:26:27 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	std::cout << type << " Constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << type << " Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &a){
	if (this != &a){
		type = a.type;
	}
	std::cout << type << " Assignment operator called" << std::endl;
	return (*this);
}

Dog::Dog(const Dog &a): Animal(a){
	*this = a;
	std::cout << type << " Copy constructor called" << std::endl;
}

std::string Dog::getType() const{
	return (this->type);
}

void Dog::makeSound() const{
	std::cout << this->type << " is barking" << std::endl;
}