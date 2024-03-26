/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:51:06 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 17:59:36 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){

}

Weapon::Weapon(std::string type){
	this->_type = type;
}

Weapon::~Weapon(){

}

void Weapon::setType(std::string type){
	this->_type = type;
}

std::string &Weapon::getType(){
	return (this->_type);
}

