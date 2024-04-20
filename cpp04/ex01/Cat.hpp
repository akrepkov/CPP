/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:18:19 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 15:22:35 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
	private:
		Brain* brain;
	protected:
		std::string type;

	public:
		Cat();
		virtual ~Cat();
		Cat& operator=(const Cat &a);
		Cat(const Cat &a);
		virtual std::string getType() const;
		virtual void makeSound() const;

};

#endif