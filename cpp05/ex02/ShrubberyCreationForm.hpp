/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:58:20 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 14:21:49 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm{
	private:
		const std::string name;
		bool sign;
		int SignGrade;
		int ExecuteGrade;
		std::string target;	

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& a);
		ShrubberyCreationForm (const ShrubberyCreationForm& a);
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getSign() const;
		void beSigned(Bureaucrat const & a);
		virtual void execute(Bureaucrat const & executor) const;
};

#endif