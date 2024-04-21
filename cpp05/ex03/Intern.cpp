/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:22:09 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 14:49:40 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

AForm *Intern::makeShrub(std::string target){
	return(new ShrubberyCreationForm(target));
}
AForm *Intern::makeRobot(std::string target){
	return(new RobotomyRequestForm(target));
}
AForm *Intern::makePresident(std::string target){
	return(new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target){
	std::string givenName[3] = {"Shrubbery", "Robotomy", "President"};
	AForm* (Intern::*fptr[3])(std::string) = {&Intern::makeShrub, &Intern::makeRobot, &Intern::makePresident};
	for (int i = 0; i < 3; i++){
		if (name == givenName[i]){
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*fptr[i])(target));
		}
	}
	throw std::invalid_argument("The form doesn't exist");
	return(NULL);
}
