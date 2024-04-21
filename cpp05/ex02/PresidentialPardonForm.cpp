/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:27:07 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/12 15:55:56 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm(), name("President"), SignGrade(25), ExecuteGrade(5){
	sign = false;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Robotomy", 25, 5){
	sign = false;
	this->SignGrade = 25;
	this->ExecuteGrade = 5;
	this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &a){
	if (this != &a){
		sign = a.sign;
		SignGrade = a.SignGrade;
		ExecuteGrade = a.ExecuteGrade;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a): AForm(a){
	*this = a;
}

int PresidentialPardonForm::getSignGrade() const{
	return(SignGrade);
}

int PresidentialPardonForm::getExecuteGrade() const{
	return(ExecuteGrade);
}

bool PresidentialPardonForm::getSign() const{
	return(sign);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (sign == true){
		if (executor.getGrade() >= ExecuteGrade){
			throw AForm::GradeTooHighException();
		}
		else if (SignGrade < 1 || ExecuteGrade < 1)
			throw AForm::GradeTooLowException();
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw std::invalid_argument("The form was't signed");
}

void PresidentialPardonForm::beSigned(Bureaucrat const & a) {
	if (sign == true)
		throw std::invalid_argument("The form was already signed");
	else if(a.getGrade() > SignGrade)
			throw AForm::GradeTooLowException();
	else if (SignGrade < 1 || ExecuteGrade < 1 || a.getGrade() < 1)
		throw AForm::GradeTooHighException();
	else{
		sign = true;
		std::cout << "The PresidentialPardonForm was signed" << std::endl;
	}
}