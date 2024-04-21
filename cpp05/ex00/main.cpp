/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:55:28 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 13:19:43 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "Bureaucrat.hpp"

int main(){
	Bureaucrat* bureaucrat[6] = {};
	for (int i = 0; i < 6; i++){
		try{
			std::cout << "\033[1;31mTest " << i << "\033[0m" << std::endl;
			int grade[6] = {-1, 1, 10, 149, 150, 151};
			std::string name[6] = {"John", "Alice", "Bob", "Emily", "Michael", "James"};
			bureaucrat[i] = new Bureaucrat(name[i], grade[i]);
			std::cout << *bureaucrat[i];
			if (i < 3){
				bureaucrat[i]->upGrade();
				std::cout << *bureaucrat[i];
			}
			else{
				bureaucrat[i]->deGrade();
				std::cout << *bureaucrat[i];
			}
			delete bureaucrat[i];
		} catch(std::exception &e){
			std::cout << e.what() << std::endl;
			delete bureaucrat[i];
			continue ;
		}
	}
	return 0;
}
