/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:19:35 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 15:26:27 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << type << " Constructor called" << std::endl;
}

WrongCat::~WrongCat(){	
	std::cout << type << " Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &a){
	std::cout << type << " Assignment operator called" << std::endl;
	if (this != &a){
		type = a.type;
	}
	return (*this);
}

WrongCat::WrongCat(const WrongCat &a): WrongAnimal(a){
	std::cout << type << " Copy constructor called" << std::endl;
	*this = a;
}

std::string WrongCat::getType() const{
	return (this->type);
}

void WrongCat::makeSound() const{
	std::cout << this->type << " is mooing" << std::endl;
}