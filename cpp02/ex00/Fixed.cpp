/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:33:08 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 17:45:45 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_x = 0;
}

Fixed::Fixed(Fixed& a){
	std::cout << "Copy constructor called" << std::endl;
	this->_x = a.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& a){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a){ // Avoid self-assignment
		this->_x = a.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_x);
}

void Fixed::setRawBits(int const raw){
	this->_x = raw;
}
