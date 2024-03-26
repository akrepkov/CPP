/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:59:34 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 14:00:26 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include "Harl.hpp"

int main(int argc, char **argv){
	Harl harl;
	if (argc != 2){
		std::cerr << "Wrong amount of arguments" << std::endl;
		exit (1);
	}
	std::string level = argv[1];
	harl.complain(level); //how to cast?
	return 0;
}