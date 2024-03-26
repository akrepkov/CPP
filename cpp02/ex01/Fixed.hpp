/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:32:20 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 17:35:05 by akrepkov         ###   ########.fr       */
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
		Fixed (const int y);
		Fixed (const float y);
		Fixed(const Fixed& copy);
/*Operator overloading*/
		Fixed& operator=(const Fixed& a);
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