/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:08:33 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/06 17:25:14 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP
#include <string>
#include <iostream>
class ScalarConverter{
	public:
		static void convert(const std::string& literal);
		static void convert(std::nullptr_t);



};

#endif
