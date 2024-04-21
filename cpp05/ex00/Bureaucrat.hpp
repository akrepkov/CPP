/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:43:41 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/13 14:01:49 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
/*If the value is the same for all objects of the class, then, 
of course, it should be a static const member of the class.

If different objects might require different values, then 
it should be just a non-static const member.*/
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


#endif