/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:43:07 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/13 14:03:21 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("bureaucrat"), grade(150){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name){ 
	//The line : name(name) in the constructor is called a constructor initialization list. 
	//It initializes the name member variable with the value passed as a parameter to the constructor.
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &a){
	if (this != &a){
		this->grade = a.getGrade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &a){
	*this = a;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a){
	os << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
	return (os);
}

std::string Bureaucrat::getName() const{
	return (name);
}

int Bureaucrat::getGrade() const{
	return (grade);
}

Bureaucrat& Bureaucrat::upGrade(){
	if (grade == 1)
		throw GradeTooHighException();
	else {
		this->grade -= 1;
		std::cout << "Our bureaucrat is climbing the career ladder" << std::endl;
	}
	return (*this);
}

Bureaucrat& Bureaucrat::deGrade(){
	if (grade == 150)
		throw GradeTooLowException();
	else {
		this->grade += 1;
		std::cout << "Our bureaucrat made too many mistakes this year" << std::endl;
	}
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept{ 
	return ("The grade is too high"); 
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept{ 
	return ("The grade is too low"); 
}