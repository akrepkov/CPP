/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:38:53 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 13:56:00 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(){
	Harl harl;
	std::cout << "DEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO" << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR" << std::endl;
	harl.complain("ERROR");
	return 0;
}