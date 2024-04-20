/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:39:49 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 10:59:48 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(){
	_name = "Default";
	_hit = 0;
	_energy = 0;
	_damage = 0;
	_maxXP = 0;
	std::cout << "\033[2;20;40mDiamondTrap Constructor was called\033[0m\t\t" << std::endl;
}
DiamondTrap::~DiamondTrap(){
	std::cout << "\033[2;20;40mDiamondTrap Destructor was called\033[0m\t\t" << std::endl;

}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
	ClapTrap::setName(name + "_clap_name");
	_name = name;
	FragTrap::_hit = 100;
	ScavTrap::_energy = 100;
	FragTrap::_damage = 30;
	FragTrap::_maxXP = _hit;
	std::cout << "\033[2;20;40mDiamondTrap Constructor was called\033[0m\t\t" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& a)
{
	std::cout << this->FragTrap::getName() << "\033[2;20;40mDDiamondTrap Copy assignment operator was called\033[0m\t\t" << std::endl;
	if (this != &a){
		_energy = a._energy;
		_hit = a._hit;
		_damage = a._damage;
		_maxXP = _hit;
	}
	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap& a) : ClapTrap(a._name + "_clap_name"), ScavTrap(a._name), FragTrap(a._name)
{    std::cout << _name << "\033[2;20;40m DiamondTrap Copy constructor was called\033[0m\t\t" << std::endl;
	*this = a;
}

void DiamondTrap::whoAmI(){
 std::cout << "My name is " << _name << ", and my weird name is " << ClapTrap::_name << std::endl;
 /*This initialization only affects the _name member of the ClapTrap part of the DiamondTrap object being constructed. 
 It does not affect the _name member of the ClapTrap class itself or any other ClapTrap objects.*/
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}