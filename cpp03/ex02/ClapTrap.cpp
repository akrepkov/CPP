/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:35 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 16:48:49 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	_name = "Default";
	_hit = 0;
	_energy = 0;
	_damage = 0;
	_maxXP = 0;
	std::cout << _name << "\033[2;20;40m Constructor was called\033[0m\t\t" << std::endl;
}
ClapTrap::ClapTrap(std::string name){
	_name = name;
	_hit = 10;
	_energy = 10;
	_damage = 0;
	_maxXP = _hit;
	std::cout << "\033[2;20;40mClapTrap Constructor was called\033[0m\t\t" << std::endl;
}
ClapTrap::~ClapTrap(){
	std::cout << "\033[2;20;40mClapTrap Destructor was called\033[0m\t\t" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& a){
	std::cout << getName() << "\033[2;20;40mD Copy assignment operato was called\033[0m\t\t" << std::endl;
	if (this != &a){
		_energy = a._energy;
		_hit = a._hit;
		_damage = a._damage;
	}
	return *this;
}
ClapTrap::ClapTrap(const ClapTrap& a){
	std::cout << getName() << "\033[2;20;40mClapTrap Copy constructor was called\033[0m\t\t" << std::endl;
	*this = a;
}
void ClapTrap::attack(const std::string& target){
	if (_hit < 0 || _energy <= 0 || _damage < 0){
		std::cout << "It's unacceptable!" <<std::endl;
		throw "exiting";
	}
	_energy -= 1;
	std::cout << getName() << " attacks " << target <<
	", causing " << getDamage() << " points of damage!" << std::endl;
	if (_hit <= 0 || _energy <= 0 ){
		std::cout << _name << " was beaten due to loosing all the energy!" <<std::endl;
		throw "exiting";
	}
}
void ClapTrap::takeDamage(unsigned int amount){
	_hit -= amount;
	if (_hit <= 0 || _energy <= 0 ){
		std::cout << _name << " was beaten!" <<std::endl;
		throw "exiting";
	}
	std::cout << getName() << " takes damage and has " << getHit() <<
	" points of health left" << std::endl;

}
void ClapTrap::beRepaired(unsigned int amount){

	_energy -= 1;
	_hit = ((_hit + (int)amount) > _maxXP) ? _maxXP : _hit + amount;
	std::cout << getName() << " restores his health on " << amount <<
	" points and has " << getEnergy() << " points of energy left!" << std::endl;	
	if (_hit <= 0 || _energy <= 0 ){
		std::cout << _name << " was beaten due to loosing all the energy!" <<std::endl;
		throw "exiting";
	}
}
std::string ClapTrap::getName() const{
	return (_name);
}
int ClapTrap::getHit() const{
	return (_hit);
}
int ClapTrap::getEnergy() const{
	return (_energy);
}
int ClapTrap::getDamage() const{
	return (_damage);
}
void ClapTrap::setName(std::string name){
	_name = name;
	return ;
}
void ClapTrap::setHit(int amount){
	_hit = amount;
	_maxXP = _hit;
}
void ClapTrap::setEnergy(int amount){
	_energy = amount;
}
void ClapTrap::setDamage(int amount){
	_damage = amount;
}
