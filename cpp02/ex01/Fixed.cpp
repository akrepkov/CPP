/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:33:08 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 17:36:04 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*Constructor*/
Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_x = 0;
}
Fixed::Fixed (const int y){
	std::cout << "Int constructor called" << std::endl;
	this->_x = y << _bits;
}
	/* Percision of float equals 7 digits after dot. 
	To convert from floating-point to fixed-point, we follow this algorithm:
	Calculate x = floating_input * 2^(fractional_bits)
	Round x to the nearest whole number (e.g. round(x))
	Store the rounded x in an integer container*/
Fixed::Fixed (const float y){
	this->_x = roundf(y * (1 << _bits));
	std::cout << "Float constructor called " << std::endl;
}
Fixed::Fixed(const Fixed& copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

/*Operator overloading*/
Fixed& Fixed::operator=(const Fixed& a){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a){
		this->_x = a.getRawBits();
	}
	return (*this);
}
std::ostream& operator<<(std::ostream& os,const Fixed& a){
	os << a.toFloat();
	return (os);
}

/*Destuctor*/
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

/*Getters and setters*/
int Fixed::getRawBits() const {
	return (this->_x);
}

void Fixed::setRawBits(int const raw){
	this->_x = raw;
}

/*Fixed to float/int*/
float Fixed::toFloat (void) const{
	return ((float)_x / (float(1 << _bits)));
}

int Fixed::toInt(void) const{
	return (_x >> _bits);
}
