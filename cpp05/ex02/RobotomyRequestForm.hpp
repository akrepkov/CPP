/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:58:20 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/12 15:51:05 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm{
	private:
		const std::string name;
		bool sign;
		int SignGrade;
		int ExecuteGrade;
		std::string target;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& a);
		RobotomyRequestForm (const RobotomyRequestForm& a);
		int getSignGrade() const;
		bool getSign() const;
		int getExecuteGrade() const;
		void beSigned(Bureaucrat const & a);
		virtual void execute(Bureaucrat const & executor) const;
};

#endif