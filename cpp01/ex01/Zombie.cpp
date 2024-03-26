/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:04:02 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/08 16:05:29 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
};

Zombie::Zombie(std::string name){
	this->name = name;
};

Zombie::~Zombie(){
	std::cout << this->name << " destroyed!" << std::endl;
};

void Zombie::announce(){
	std::cout << "Hi, I'm " << this->name << std::endl;
}

void Zombie::setname(std::string name){
	this->name = name;
}
