/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:09:48 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 18:59:06 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(){
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << &str << " string adress" << std::endl;
	std::cout << stringPTR << " stringPTR address" << std::endl;
	std:: cout << &stringREF << " stringREF address" << std::endl;

	std::cout << str << " string value" << std::endl;
	std::cout << *stringPTR << " value pointed to by stringPTR" << std::endl;
	std:: cout << stringREF << " value pointed to by stringREF" << std::endl;	
}