/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:35 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 13:04:24 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "\033[2;47;35mConstructor was called\033[0m\t\t" << std::endl;
}
ClapTrap::ClapTrap(std::string name){
	std::cout << "\033[2;20;40mConstructor was called\033[0m\t\t" << std::endl;
	this->_name = name;
	this->_hit = 10;
	this->_energy = 10;
	this->_damage = 0;
}
ClapTrap::~ClapTrap(){
	std::cout << "\033[2;20;40mDestructor was called\033[0m\t\t" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& a){
	std::cout << "\033[2;20;40mDCopy assignment operator was called\033[0m\t\t" << std::endl;
	if (this != &a){
		_energy = a._energy;
		_hit = a._hit;
		_damage = a._damage;
		next = nullptr;
	}
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap& a){
	std::cout << "\033[2;20;40mCCopy constructor was called\033[0m\t\t" << std::endl;
	*this = a;
}

void ClapTrap::attack(const std::string& target){
	next->_hit -= this->_damage;
	std::cout << "ClapTrap " << this->_name << \
	" attacks " << target << ", causing " <<  \
	this->_damage << " points of damage!" << std::endl;
	next->takeDamage(_damage);
}
void ClapTrap::takeDamage(unsigned int amount){
	this->_energy -= amount;
	std::cout << "ClapTrap " << this->_name << \
	" takes " << amount << " points of damage and looses " << amount
	<< " points of energy!" << std::endl;
	if (this->_hit <= 0 || this->_energy <= 0 ){
		std::cout << "ClapTrap " << _name << " was beaten!" <<std::endl;
		throw "exiting";
	}

}
void ClapTrap::beRepaired(unsigned int amount){
	this->_energy -= amount;
	this->_hit += amount;
	std::cout << "ClapTrap " << this->_name << \
	" spends " << amount << " points energy." << " Now his health is " << _hit << " points." << std::endl;	
	if (this->_hit <= 0 || this->_energy <= 0 ){
		std::cout << "ClapTrap " << _name << " was beaten due to loosing all the energy!" <<std::endl;
		throw "exiting";
	}
}

std::string ClapTrap::getName() const{
	return (_name);
}

void ClapTrap::setObj(ClapTrap* b){
	this->next = b;
}

ClapTrap* ClapTrap::getObj(){
	return (this->next);
}

void ClapTrap::setDamage(int amount){
	this->_damage = amount;
}

