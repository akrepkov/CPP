/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:43:41 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 13:58:41 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &a);
		Bureaucrat(const Bureaucrat &a);
		std::string getName() const;
		int getGrade() const;
		Bureaucrat& upGrade();
		Bureaucrat& deGrade();
		void signForm(AForm& a);
		void executeForm(AForm const& form);
	class GradeTooHighException: public std::exception{
		public:
			const char* what() const noexcept;
			};
	class GradeTooLowException: public std::exception{
		public:
			const char* what() const noexcept;
			};
		};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a);
// void logError(const std::string &errorMessage);

#endif