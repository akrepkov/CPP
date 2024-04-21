/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:27:07 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 14:22:13 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("Shrubbery", 145, 137){
	sign = false;
}

std::string print_tree(){
	std::string tree;

	tree += "###########\n";
	tree += "#    |    #\n";
	tree += "#   / \\   #\n";
	tree += "#  /\\ /\\  #\n";
	tree += "###########\n";
	return (tree);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("Shrubbery", 145, 137){
	sign = false;
	this->SignGrade = 145;
	this->ExecuteGrade = 137;
	this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a){
	if (this != &a){
		sign = a.sign;
		SignGrade = a.SignGrade;
		ExecuteGrade = a.ExecuteGrade;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a): AForm(a){
	*this = a;
}

int ShrubberyCreationForm::getSignGrade() const{
	return(SignGrade);
}

int ShrubberyCreationForm::getExecuteGrade() const{
	return(ExecuteGrade);
}

bool ShrubberyCreationForm::getSign() const{
	return(sign);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (sign == true){
		if (executor.getGrade() >= ExecuteGrade){
			throw AForm::GradeTooHighException();
		}
		else if (SignGrade < 1 || ExecuteGrade < 1)
			throw AForm::GradeTooLowException();
		std::ofstream outputFile;
		outputFile.open((target + "_shrubbery").c_str());
		if (!outputFile){
			throw std::invalid_argument("Unable to open file: " + target + "_shrubbery");
		}
		else{
			outputFile << print_tree() << std::endl;
			outputFile.close();
		}
	}
	else
		throw std::invalid_argument("Error: The form was't signed");
}

void ShrubberyCreationForm::beSigned(Bureaucrat const & a){
	if (sign == true)
		throw std::invalid_argument("The form was already signed");
	else if(a.getGrade() > SignGrade)
			throw Bureaucrat::GradeTooLowException();
	else if (SignGrade < 1 || ExecuteGrade < 1)
		throw AForm::GradeTooHighException();
	else{
		sign = true;
		std::cout << "The ShrubberyCreationForm was signed" << std::endl;
	}
}
