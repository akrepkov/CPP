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
#include "Brain.hpp"

Cat::Cat(){
	this->type = "Cat";
	brain = new Brain();
}

Cat::~Cat(){
	delete brain;
}

Cat& Cat::operator=(const Cat &a){
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

Cat::Cat(const Cat &a): Animal(a){
	this->type = a.type;
	if (a.brain){
		this->brain = new Brain();
		this->brain = a.brain;
	}
	else
		this->brain = nullptr;
	*this = a;
}

std::string Cat::getType() const{
	return (this->type);
}

void Cat::makeSound() const{
	std::cout << this->type << " is meouwing" << std::endl;
}