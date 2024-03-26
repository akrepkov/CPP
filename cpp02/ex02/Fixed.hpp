/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:15:36 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 17:30:55 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

//operation*(Fixed &a, Fixed &b) = a.operation*(Fixed &b)

class Fixed{
	private:
		int _x;
		static const int _bits = 8;

	public:
/*Constructor*/
		Fixed();
		Fixed (const int a);
		Fixed (const float a);
		Fixed(const Fixed& a);
/*Operator overloading*/
		Fixed& operator=(const Fixed &a);
		Fixed operator+(const Fixed &b)const;
		Fixed operator-(const Fixed &b)const;
		Fixed operator*(const Fixed &b)const;
		Fixed operator/(const Fixed &b) const;
		Fixed& operator++();
		Fixed operator++(int); //fictive parametr
		Fixed& operator--();
		Fixed operator--(int); //fictive parametr
		bool operator>(const Fixed &b)const;
		bool operator>=(const Fixed &b)const;		
		bool operator<(const Fixed &b)const;
		bool operator<=(const Fixed &b)const;
		bool operator==(const Fixed &b)const;
		bool operator!=(const Fixed &b)const;
/*Overloaded functions*/
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
/*Destuctor*/
		~Fixed();
/*Getters and setters*/
		int		getRawBits() const;
		void	setRawBits(int const raw);
/*Fixed to float/int*/
		/*Preventing Modification: By declaring toFloat as a const member function, 
		you ensure that it doesn't modify the internal state of the Fixed object. 
		This is important for maintaining const correctness and preventing accidental modifications of objects 
		when they are accessed through const references or pointers.*/
		float	toFloat (void) const;
		int		toInt(void) const;
};
std::ostream& operator<<(std::ostream& os,const Fixed& a);


#endif
