/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:39:49 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 13:16:50 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	_name = "Default";
	_hit = 0;
	_energy = 0;
	_damage = 0;
	_maxXP = 0;
	std::cout << "\033[2;20;40mTarget Constructor was called\033[0m\t\t" << std::endl;
}
ScavTrap::~ScavTrap(){
	std::cout << "\033[2;20;40mTarget Destructor was called\033[0m\t\t" << std::endl;
}
ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	_name = "Target";
	_hit = 100;
	_energy = 50;
	_damage = 20;
	_maxXP = _hit;
	std::cout << "\033[2;20;40mTarget Constructor was called\033[0m\t\t" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& a){
	std::cout << this->getName() << "\033[2;20;40mD Copy assignment operator was called\033[0m\t\t" << std::endl;
	if (this != &a){
		_energy = a._energy;
		_hit = a._hit;
		_damage = a._damage;
	}
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap& a):ClapTrap(a){
	std::cout << _name << "\033[2;20;40m Copy constructor was called\033[0m\t\t" << std::endl;
	*this = a;
}

void ScavTrap::guardGate(){
	std::cout << _name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (_hit < 0 || _energy <= 0 || _damage < 0){
		std::cout << "It's unacceptable!" <<std::endl;
		throw "exiting";
	}
	_energy -= 1;
	std::cout << "\033[2;36;40m"<< getName() << " attacks " << target <<
	", causing " << getDamage() << " points of damage!\033[0m\t\t" << std::endl;
	if (_hit <= 0 || _energy <= 0 ){
		std::cout << _name << " was beaten due to loosing all the energy!" <<std::endl;
		throw "exiting";
	}
}

