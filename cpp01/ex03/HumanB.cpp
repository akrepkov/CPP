/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:04:33 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 19:09:04 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(){

};

HumanB::HumanB(std::string name){
	this->_name = name;
};

HumanB::~HumanB(){

};
void HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}
void HumanB::attack(){
	std::cout << _name << " attacks with their " << weapon->getType() << std::endl;
}
