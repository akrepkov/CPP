/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:41:26 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 14:02:19 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


void Harl::_debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-" <<
	"pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::_info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. " <<
	"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << 
	std::endl;
}

void Harl::_warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. " <<
	"I’ve been coming for years whereas you started working here since last month" << 
	std::endl;
}

void Harl::_error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void Harl::complain(std::string level){
	std::string complaint[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fptr[4])() = {&Harl::_debug, &Harl::_info,  &Harl::_warning,  &Harl::_error};
	for (int i = 0; i < 4; i++){
		if (level == complaint[i]){
			switch(i){
			case 0:
				(this->*fptr[i++])();
			case 1:
				(this->*fptr[i++])();
			case 2:
				(this->*fptr[i++])();
			case 3:
				(this->*fptr[i++])();				
			}
			return;
		}
	}
	std::cerr << "Probably complaining about insignificant problems" << std::endl;
}