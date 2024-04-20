/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:18:19 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 15:22:35 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	protected:
		std::string type;

	public:
		WrongCat();
		~WrongCat();
		WrongCat& operator=(const WrongCat &a);
		WrongCat(const WrongCat &a);
		virtual std::string getType() const;
		virtual void makeSound() const;

};

#endif