/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:42:52 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 18:30:46 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>
#include <iomanip>
#include <iostream>
#include "Weapon.hpp"

class HumanA{
	private:
		std::string _name;
		Weapon *weapon;
	
	public:
		HumanA();
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif