/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:18:19 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/03 10:27:32 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain{
	protected:
		std::string ideas[100]; //change to 100

	public:
		Brain();
		virtual ~Brain();
		Brain& operator=(const Brain &a);
		Brain(const Brain &a);
		// virtual std::string getType() const;
		// virtual void makeSound() const;

};

#endif