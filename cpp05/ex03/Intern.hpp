/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:22:12 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/19 12:26:01 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
#define Intern_HPP
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern& operator=(const Intern& a);
		Intern(const Intern& a);
		AForm* makeForm(std::string name, std::string target);
		AForm *makePresident(std::string target);
		AForm *makeRobot(std::string target);
		AForm *makeShrub(std::string target);
};


#endif

