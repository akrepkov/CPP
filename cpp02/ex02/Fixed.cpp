/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:15:34 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 17:29:11 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*Constructor*/
Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
	this->_x = 0;
}
Fixed::Fixed (const int y){
	// std::cout << "Int constructor called" << std::endl;
	this->_x = y << _bits;
}
Fixed::Fixed (const float y){
	// std::cout << "Float constructor called " << std::endl;
	this->_x = roundf(y * (1 << _bits));
}
Fixed::Fixed(const Fixed& copy){
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

/*Operator overloading*/
Fixed& Fixed::operator=(const Fixed &a){
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a){
		this->_x = a.getRawBits();
	}
	return (*this);
}
Fixed Fixed::operator+(const Fixed &b) const{
	Fixed c;
	c.setRawBits(this->_x + b.getRawBits());
	return c;
}
Fixed Fixed::operator-(const Fixed &b) const{
	Fixed c;
	c.setRawBits(this->_x - b.getRawBits());
	return c;
}
Fixed Fixed::operator*(const Fixed &b) const{
	Fixed c;
	c.setRawBits(this->_x * b.getRawBits() >> _bits);
	return c;
}
Fixed Fixed::operator/(const Fixed &b) const{
    Fixed c;
	if (b.toFloat() != 0)
		c.setRawBits((this->_x << _bits) / b.getRawBits());
	else
		std::cerr <<"Divide 0" << std::endl;
	return c;
}
std::ostream& operator<<(std::ostream &os,const Fixed &a){
	os << a.toFloat();
	return (os);
}

/*Destuctor*/
Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

/*Getters and setters*/
int Fixed::getRawBits() const {
	
	return (this->_x);
}

void Fixed::setRawBits(int const raw){
	this->_x = raw;
}

float Fixed::toFloat (void) const{
	return (static_cast<float>(this->_x) / (1 << _bits));
}

int Fixed::toInt(void) const{
	return (_x >> _bits);
}

Fixed& Fixed::operator++(){
	++this->_x;
	return (*this);
}
Fixed Fixed::operator++(int){
	Fixed temp = this->toFloat();
	++(*this);
	return (temp);
}

Fixed& Fixed::operator--(){
	--this->_x;
	return (*this);
}
Fixed Fixed::operator--(int){
	Fixed temp = this->toFloat();
	--(*this);
	return (temp);
}

bool Fixed::operator>(const Fixed &b)const{
	return (this->_x > b.getRawBits());
}
bool Fixed::operator>=(const Fixed &b)const{
	return (this->_x >= b.getRawBits());
}
bool Fixed::operator<(const Fixed &b)const{
	return (this->_x < b.getRawBits());
}
bool Fixed::operator<=(const Fixed &b)const{
	return (this->_x <= b.getRawBits());
}
bool Fixed::operator==(const Fixed &b)const{
	return (this->_x == b.getRawBits());
}
bool Fixed::operator!=(const Fixed &b)const{
	return (this->_x != b.getRawBits());
}

Fixed& Fixed::min(Fixed &a, Fixed &b){
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}
Fixed& Fixed::max(Fixed &a, Fixed &b){
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b){
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}
