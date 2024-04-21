/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:55:28 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 13:51:23 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	Form* form[6] = {};
	Bureaucrat* bureaucrat[6] = {}; // инициализация переменной по умолчанию значением 0 (ноль)
	int grade[6] = {-1, 1, 10, 149, 150, 151};
	int form_grade[6] = {1, -1, 8, 150, 151, 150};
	std::string name[6] = {"John", "Alice", "Bob", "Emily", "Michael", "James"};		
	for (int i = 0; i < 6; i++){
		try{
			std::cout << "\033[1;31mTest " << i << "\033[0m" << std::endl;
			form[i] = new Form(form_grade[i]);
			bureaucrat[i] = new Bureaucrat(name[i], grade[i]);
			std::cout << *bureaucrat[i];
			if (i < 3){
				bureaucrat[i]->signForm(*form[i]);
				form[i]->beSigned(*bureaucrat[i]);
				std::cout << *form[i];
				bureaucrat[i]->upGrade();
				std::cout << *bureaucrat[i];
			}
			else{
				bureaucrat[i]->signForm(*form[i]);
				form[i]->beSigned(*bureaucrat[i]);
				std::cout << *form[i];
				bureaucrat[i]->deGrade();
				std::cout << *bureaucrat[i];
			}
		} catch(std::exception& e){
			std::cout << e.what() << std::endl;	
			continue ;
		}
	}
    for (int i = 0; i < 6; i++){
        delete bureaucrat[i];
        delete form[i];
    }
	return 0;
}
