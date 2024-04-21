/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:33:12 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 13:49:05 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*If it's const - initialize member variables in the constructor and copy constructor*/

Form::Form(): name("form"), SignGrade(10), ExecuteGrade(10){
	sign = false;
}

Form::~Form(){

}

Form::Form(int grade): name("form"), SignGrade(grade), ExecuteGrade(10){
	sign = false;
	if (SignGrade > 150 || ExecuteGrade > 150)
		throw GradeTooLowException();
	else if (SignGrade < 1 || ExecuteGrade < 1)
		throw GradeTooHighException();
}

Form& Form::operator=(const Form& a){
	if (this != &a){
		this->sign = a.sign;
	}
	return (*this);
}
Form::Form(const Form& a): SignGrade(a.SignGrade), ExecuteGrade(a.ExecuteGrade) {
	this->sign = a.sign;
}

std::string Form::getName() const{
	return(name);
}

int Form::getSignGrade() const{
	return(SignGrade);
}

int Form::getExecuteGrade() const{
	return(ExecuteGrade);
}

bool Form::getSign() const{
	return(sign);
}

void Form::beSigned(Bureaucrat const & a){
	if (SignGrade < a.getGrade())
		throw GradeTooHighException();
	this->sign = true;
	std::cout << "The form was signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& a){
	os << "The Form Sign grade is " << a.getSignGrade() << std::endl;
	os << "The Form Execute grade is " << a.getExecuteGrade() << std::endl;
	os << "The Form signature status is " << std::boolalpha << a.getSign() << std::endl;
	return (os);
}

const char* Form::GradeTooHighException::what() const noexcept{ 
	return ("The form grade is too high"); 
}

const char* Form::GradeTooLowException::what() const noexcept{ 
	return ("The form grade is too low"); 
} 