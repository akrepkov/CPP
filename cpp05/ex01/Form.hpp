/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:58:38 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 13:44:05 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat; //This happens because the Bureaucrat class is declared after the Form class in your code.

class Form{
	private:
		const std::string name;
		bool sign;
		const int SignGrade;
		const int ExecuteGrade;	
	public:
		Form();
		~Form();
		Form(int grade);
		Form& operator=(const Form& a);
		Form(const Form& a);
		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getSign() const;
		void beSigned(Bureaucrat const & a);			
	class GradeTooHighException: public std::exception{
		public:
			const char* what() const noexcept;
			};
	class GradeTooLowException: public std::exception{
		public:
			const char* what() const noexcept;
			};
};

std::ostream& operator<<(std::ostream& os, const Form& a);



#endif
