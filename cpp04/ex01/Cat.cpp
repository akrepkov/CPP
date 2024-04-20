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
	std::cout <<  "\033[2;20;40m" <<  type << " Constructor called\033[0m\t\t" << std::endl;

}

Cat::~Cat(){
	delete brain;
	std::cout << "\033[2;20;40m" <<   type << " Destructor called\033[0m\t\t" << std::endl;
}

Cat& Cat::operator=(const Cat &a){
	if (this == &a){
		return *this;
	}
	std::cout << "\033[2;20;40m" <<   type << " Assignment operator called\033[0m\t\t" << std::endl;
	delete brain;
	if (a.brain){
		this->brain = new Brain();
		this->brain = a.brain;
	}
	else
		this->brain = nullptr;	
	return (*this);
}

Cat::Cat(const Cat &a): Animal(a){
	std::cout << "\033[2;20;40m" <<   type << " Copy constructor called\033[0m\t\t" << std::endl;
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