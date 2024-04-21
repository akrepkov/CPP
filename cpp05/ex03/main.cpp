/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:55:28 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 14:54:04 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// void logError(const std::string &errorMessage)
// {
// 	std::ofstream logfile("error.log", std::ios_base::app); // append mode
// 	if (!logfile.is_open())
// 	{
// 		std::cerr << "Error: Unable to open log file for writing!" << std::endl;
// 		return;
// 	}
// 	logfile << "Error: " << errorMessage << std::endl;
// 	logfile.close();
// }

int main()
{
	Bureaucrat bureaucrat("Jack", 10);
	Intern Peter;
	std::string target = "Anna";
	AForm* a;
	for (int i = 0; i < 6; i++){
		try{
			if (i == 0){
				std::cout << "\033[1;31mThe form was created\033[0m" << std::endl;
				a = Peter.makeForm("Robotomy", target);
				a->beSigned(bureaucrat);
				bureaucrat.signForm(*a);
				bureaucrat.executeForm(*a);
				delete a;
			}
			else if (i == 1){
				std::cout << "\033[1;31mThe form was created\033[0m" << std::endl;
				a = Peter.makeForm("Shrubbery", target);
				a->beSigned(bureaucrat);
				bureaucrat.signForm(*a);
				bureaucrat.executeForm(*a);
				delete a;
			}
			else if (i == 2){
				std::cout << "\033[1;31mThe bureaucrat grade is too low\033[0m" << std::endl;
				a = Peter.makeForm("President", target);
				a->beSigned(bureaucrat);
				bureaucrat.signForm(*a);
				bureaucrat.executeForm(*a);
				delete a;
			}
			else if (i == 3){
				std::cout << "\033[1;31mError\033[0m" << std::endl;
				a = Peter.makeForm("Anna", target);
				a->beSigned(bureaucrat);
				bureaucrat.signForm(*a);
				bureaucrat.executeForm(*a);
			}
		}catch (std::exception& e){
			std::cout << "Error: " << e.what() << std::endl;
			}
		// }catch (std::exception &e){
		// 	logError(e.what());
		// }
	}
	return 0;
}