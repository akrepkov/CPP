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
#include "Brain.hpp"

Dog::Dog(){
	this->type = "Dog";
	brain = new Brain();

}

Dog::~Dog(){
	delete brain;
}

Dog& Dog::operator=(const Dog &a){
	if (this != &a){
		return *this;
	}
	delete brain;
	if (a.brain){
		this->brain = new Brain();
		this->brain = a.brain;
	}
	else
		this->brain = 0;	
	return (*this);
}

Dog::Dog(const Dog &a): Animal(a){
	this->type = a.type;
	if (a.brain){
		this->brain = new Brain();
		this->brain = a.brain;
	}
	else
		this->brain = nullptr;
	*this = a;
}

std::string Dog::getType() const{
	return (this->type);
}

void Dog::makeSound() const{
	std::cout << this->type << " is barking" << std::endl;
}