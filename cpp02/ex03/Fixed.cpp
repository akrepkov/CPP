#include "Fixed.hpp"

/*Constructor*/
Fixed::Fixed(){
	this->_x = 0;
}
Fixed::Fixed (const int y){
	this->_x = y << _bits;
}
Fixed::Fixed (const float y){
	this->_x = roundf(y * (1 << _bits));
}

/*Copy constructor*/
Fixed::Fixed(const Fixed& copy){
	*this = copy;
}

/*Operator overloading*/
Fixed& Fixed::operator=(const Fixed &a){
	if (this != &a){
		this->_x = a.getRawBits();
	}
	return (*this);
}
Fixed Fixed::operator+(const Fixed &b) {
	Fixed c;
	c.setRawBits(this->_x + b.getRawBits());
	return c;
}
Fixed Fixed::operator-(const Fixed &b) {
	Fixed c;
	c.setRawBits(this->_x - b.getRawBits());
	return c;
}
Fixed Fixed::operator*(const Fixed &b) {
	Fixed c;
	c.setRawBits(this->_x * b.getRawBits() >> _bits);
	return c;
}
Fixed Fixed::operator/(const Fixed &b) {
    Fixed c;
	if (b.toFloat() != 0)
		c.setRawBits((this->_x << _bits) / b.getRawBits());
	else
		std::cerr <<"Divide 0" << std::endl;
	return c;
}
Fixed::~Fixed(){
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
	return (static_cast<float>(this->_x) / (1 << _bits));
}
int Fixed::toInt(void) const{
	return (_x >> _bits);
}

/*Comparison operators*/
bool Fixed::operator>(const Fixed &b){
	std::cout <<std::boolalpha;
	std::cout << (this->_x > b.getRawBits()) << " ";
	return (this->_x > b.getRawBits());
}
bool Fixed::operator>=(const Fixed &b){
	std::cout <<std::boolalpha;
	std::cout << (this->_x >= b.getRawBits()) << " ";
	return (this->_x >= b.getRawBits());
}
bool Fixed::operator<(const Fixed &b){
	std::cout <<std::boolalpha;
	std::cout << (this->_x < b.getRawBits()) << " ";
	return (this->_x < b.getRawBits());
}
bool Fixed::operator<=(const Fixed &b){
	std::cout <<std::boolalpha;
	std::cout << (this->_x <= b.getRawBits()) << " ";
	return (this->_x <= b.getRawBits());
}
bool Fixed::operator==(const Fixed &b){
	std::cout <<std::boolalpha;
	std::cout << (this->_x == b.getRawBits()) << " ";
	return (this->_x == b.getRawBits());
}
bool Fixed::operator!=(const Fixed &b){
	std::cout <<std::boolalpha;
	std::cout << (this->_x != b.getRawBits()) << " ";
	return (this->_x != b.getRawBits());
}

/*Print out*/
std::ostream& operator<<(std::ostream &os,const Fixed &a){
	os << a.toFloat();
	return (os);
}