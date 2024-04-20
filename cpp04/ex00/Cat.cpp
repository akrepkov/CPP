/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:19:35 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 15:26:27 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	std::cout << type << " Constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << type << " Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &a){
	if (this != &a){
		type = a.type;
	}
	std::cout << type << " Assignment operator called" << std::endl;
	return (*this);
}

Cat::Cat(const Cat &a): Animal(a){
	*this = a;
	std::cout << type << " Copy constructor called" << std::endl;
}

std::string Cat::getType() const{
	return (this->type);
}

void Cat::makeSound() const{
	std::cout << this->type << " is meouwing" << std::endl;
}