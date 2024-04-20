/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:18:19 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 15:22:35 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
	private:
		Brain *brain;
	protected:
		std::string type;

	public:
		Dog();
		~Dog();
		Dog& operator=(const Dog &a);
		Dog(const Dog &a);
		virtual std::string getType() const;
		virtual void makeSound() const; //must be constant + if in Animal I wrote virtal, i don't have to write it here

};

#endif