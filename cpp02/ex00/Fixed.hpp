/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:32:20 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 17:49:04 by akrepkov         ###   ########.fr       */
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
		Fixed();
		Fixed(Fixed& a);
		Fixed& operator=(const Fixed& a);
		~Fixed();
		int getRawBits() const; 
		void setRawBits( int const raw );
};

#endif