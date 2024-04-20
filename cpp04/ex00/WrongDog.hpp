/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:18:19 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 15:22:35 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongDog_HPP
#define WrongDog_HPP
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal{
	protected:
		std::string type;

	public:
		WrongDog();
		~WrongDog();
		WrongDog& operator=(const WrongDog &a);
		WrongDog(const WrongDog &a);
		std::string getType() const;
		void makeSound() const;

};

#endif