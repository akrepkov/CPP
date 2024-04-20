/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:39:49 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 16:50:45 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	_name = "Default";
	_hit = 0;
	_energy = 0;
	_damage = 0;
	_maxXP = 0;
	std::cout << "\033[2;20;40mFragTrap Constructor was called\033[0m\t\t" << std::endl;
}
FragTrap::~FragTrap(){
	std::cout << "\033[2;20;40mFragTrap Destructor was called\033[0m\t\t" << std::endl;

}
FragTrap::FragTrap(std::string name): ClapTrap(name){
	_name = name;
	_hit = 100;
	_energy = 100;
	_damage = 30;
	_maxXP = _hit;
	std::cout << "\033[2;20;40mFragTrap Constructor was called\033[0m\t\t" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& a){
	std::cout << this->getName() << "\033[2;20;40mDFragTrap Copy assignment operator was called\033[0m\t\t" << std::endl;
	if (this != &a){
		_energy = a._energy;
		_hit = a._hit;
		_damage = a._damage;
	}
	return *this;
}

FragTrap::FragTrap(const FragTrap& a): ClapTrap(a){
	std::cout << _name << "\033[2;20;40m FragTrap Copy constructor was called\033[0m\t\t" << std::endl;
	*this = a;
}

void FragTrap::highFivesGuys(void){
	std::cout << _name << " needs high five" << std::endl;
}

void FragTrap::attackRandomly(ClapTrap& a, ScavTrap &b){
	srand(time(NULL));
	int target = rand() % 2;
	if (target == 1){
		this->attack(a.getName());
		a.takeDamage(this->getDamage());
	}
	else{
		this->attack(b.getName());
		b.takeDamage(this->getDamage());	
	}

}