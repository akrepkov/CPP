/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:58:20 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/12 15:51:05 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm{
	private:
		const std::string name;
		bool sign;
		int SignGrade;
		int ExecuteGrade;	
		std::string target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& a);
		PresidentialPardonForm (const PresidentialPardonForm& a);
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getSign() const;
		virtual void beSigned(Bureaucrat const & a);
		virtual void execute(Bureaucrat const & executor) const;
};
#endif