/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:55:28 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 14:26:17 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
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
	std::string target = "Anna";
	ShrubberyCreationForm a(target);
	RobotomyRequestForm b(target);
	PresidentialPardonForm c(target);
	for (int i = 0; i < 6; i++){
		try{
			if (i == 0){
				std::cout << "\033[1;31mBureaucrat grade is too low\033[0m" << std::endl;
				Bureaucrat Jack("Jack", 150);
				std::cout << Jack;
				std::cout << a;
				a.beSigned(Jack);
			}
			else if (i == 1){
				std::cout << "\033[1;31mBureaucrat grade is too high\033[0m" << std::endl;
				Bureaucrat Jeremy("Jeremy", -1);
				std::cout << Jeremy;
				std::cout << c;
				c.beSigned(Jeremy);
			}
			else if (i == 2){
				std::cout << "\033[1;31mThe form wasn't signed\033[0m" << std::endl;
				Bureaucrat James("James", 1);
				std::cout << James;
				std::cout << b;
				James.executeForm(b);
			}
			else if (i == 3){
				std::cout << "\033[1;31mExecute ShrubberyCreationForm\033[0m" << std::endl;
				Bureaucrat Steven("Steven", 30);
				a.beSigned(Steven);
				Steven.signForm(a);
				std::cout << Steven;
				std::cout << a;
				Steven.executeForm(a);
			}
			else if (i == 4){
				std::cout << "\033[1;31mExecute RobotomyRequestForm\033[0m" << std::endl;
				Bureaucrat Kevin("Kevin", 20);
				b.beSigned(Kevin);
				Kevin.signForm(b);
				std::cout << Kevin;
				std::cout << b;
				Kevin.executeForm(b);
			}
			else if (i == 5){
				std::cout << "\033[1;31mExecute PresidentialPardonForm\033[0m" << std::endl;
				Bureaucrat Martin("Martin", 1);
				c.beSigned(Martin);
				Martin.signForm(c);
				std::cout << Martin;
				std::cout << c;
				Martin.executeForm(c);
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
