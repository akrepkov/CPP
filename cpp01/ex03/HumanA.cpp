/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:53:22 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 19:01:40 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(){

};

HumanA::HumanA(std::string name, Weapon &weapon){
	this->_name = name;
	this->weapon = &weapon;
};

HumanA::~HumanA(){

};

void HumanA::attack(){
	std::cout << _name << " attacks with their " << weapon->getType() << std::endl;
}
