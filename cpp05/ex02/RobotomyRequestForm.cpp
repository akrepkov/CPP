/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:27:07 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/12 15:55:00 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <chrono>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm():AForm(), name("Robotomy"), SignGrade(72), ExecuteGrade(45){
	sign = false;
}

void loadingEffect(std::string target){
	auto duration = 3; //in seconds
	std::string addition[] = {"|", "/", "-", "\\"};
	std::string load = "Drilling noises ";
	int i = 0;
    const auto start = std::chrono::steady_clock::now();//represents a monotonically increasing clock that’s not affected by changes to the system time.
	while (true){
		const auto current = std::chrono::steady_clock::now();
		const auto passed = std::chrono::duration_cast<std::chrono::milliseconds>(current - start).count(); //first I need to cast to milliseconds, count needs to represent milliseconds
		if (passed >= (duration * 1000))
			break;
		i++;
		if (i == 4)
			i = 0;
		std::cout << '\r' << load << addition[i]; //r is for putting cursos at the start of the line
		std::cout.flush(); //print out immediately
		usleep(200000);// time_period in microseconds
	}
	std::cout << "\r" << "Loading Complete!" << std::endl;
	srand(time(NULL));
	if ((rand() % 2) == 1)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45){
	sign = false;
	this->SignGrade = 72;
	this->ExecuteGrade = 45;
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &a){
	if (this != &a){
		sign = a.sign;
		SignGrade = a.SignGrade;
		ExecuteGrade = a.ExecuteGrade;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a): AForm(a){
	*this = a;
}

int RobotomyRequestForm::getSignGrade() const{
	return(SignGrade);
}

int RobotomyRequestForm::getExecuteGrade() const{
	return(ExecuteGrade);
}

bool RobotomyRequestForm::getSign() const{
	return(sign);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (sign == true){
		if (executor.getGrade() >= ExecuteGrade){
			throw AForm::GradeTooHighException();
		}
		else if (SignGrade < 1 || ExecuteGrade < 1)
			throw AForm::GradeTooLowException();
		else
			loadingEffect(target);
	}
	else
		throw std::invalid_argument("The form was't signed");
}

void RobotomyRequestForm::beSigned(Bureaucrat const & a) {
	if (sign == true)
		throw std::invalid_argument("The form was already signed");
	else if(a.getGrade() > SignGrade)
			throw AForm::GradeTooLowException();
	else if (SignGrade < 1 || ExecuteGrade < 1)
		throw AForm::GradeTooHighException();
	else{
		sign = true;
		std::cout << "The RobotomyRequestForm was signed" << std::endl;
	}
}