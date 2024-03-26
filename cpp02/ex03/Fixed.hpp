/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:38:25 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 16:02:37 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

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
		Fixed operator+(const Fixed &b);
		Fixed operator-(const Fixed &b);
		Fixed operator*(const Fixed &b);
		Fixed operator/(const Fixed &b);
		bool operator>(const Fixed &b);
		bool operator>=(const Fixed &b);		
		bool operator<(const Fixed &b);
		bool operator<=(const Fixed &b);
		bool operator==(const Fixed &b);
		bool operator!=(const Fixed &b);
/*Destuctor*/
		~Fixed();
/*Getters and setters*/
		int		getRawBits() const;
		void	setRawBits(int const raw);
/*Fixed to float/int*/
		float	toFloat (void) const;
		int		toInt(void) const;
};
std::ostream& operator<<(std::ostream& os,const Fixed& a);

#endif
