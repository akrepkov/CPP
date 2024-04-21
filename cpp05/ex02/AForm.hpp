/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:58:38 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/12 13:45:44 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	private:
		const std::string name;
		bool sign;
		const int SignGrade;
		const int ExecuteGrade;	
	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, int SignGrade, int ExecuteGrade);
		AForm& operator=(const AForm& a);
		AForm(const AForm& a);
		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		virtual bool getSign() const = 0;
		virtual void beSigned(Bureaucrat const & a) = 0;
		virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException: public std::exception{
		public:
			const char* what() const noexcept;
			};
	class GradeTooLowException: public std::exception{
		public:
			const char* what() const noexcept;
			};
};

std::ostream& operator<<(std::ostream& os, const AForm& a);



#endif
