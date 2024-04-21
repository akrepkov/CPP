/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:33:12 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/12 13:10:34 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm::AForm(): name("form"), SignGrade(150), ExecuteGrade(150){
	sign = false;
}

AForm::~AForm(){

}

AForm::AForm(std::string name, int SignGrade, int ExecuteGrade) : name(name), SignGrade(SignGrade), ExecuteGrade(ExecuteGrade){
	sign = false;
	if (SignGrade > 150 || ExecuteGrade > 150)
		throw GradeTooLowException();
	else if (SignGrade < 1 || ExecuteGrade < 1)
		throw GradeTooHighException();
}

AForm& AForm::operator=(const AForm& a){
	if (this != &a){
		this->sign = a.sign;
	}
	return (*this);
}
AForm::AForm(const AForm& a): SignGrade(a.SignGrade), ExecuteGrade(a.ExecuteGrade) {
	this->sign = a.sign;
}

std::string AForm::getName() const{
	return(name);
}

int AForm::getSignGrade() const{
	return(SignGrade);
}

int AForm::getExecuteGrade() const{
	return(ExecuteGrade);
}

std::ostream& operator<<(std::ostream& os, const AForm& a){
	os << "The Form Sign grade is " << a.getSignGrade() << std::endl;
	os << "The Form Execute grade is " << a.getExecuteGrade() << std::endl;
	os << "The Form signature status is " << std::boolalpha << a.getSign() << std::endl;
	return (os);
}

const char* AForm::GradeTooHighException::what() const noexcept{ 
	return ("The form grade is too high"); 
}

const char* AForm::GradeTooLowException::what() const noexcept{ 
	return ("The form grade is too low"); 
}

