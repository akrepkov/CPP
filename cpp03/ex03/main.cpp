/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:54 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 13:45:40 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

// https://isocpp.org/wiki/faq/strange-inheritance

void test(int i, ClapTrap &a, ScavTrap &b,FragTrap &c,int &amount){
	switch(i){
		case 0:
		std::cout << "\033[2;35;40mCase " << i << "\033[0m\t\t"<< std::endl;
			break;
		case 1:
		std::cout << "\033[2;35;40mCase " << i << "\033[0m\t\t"<< std::endl;
			a.setHit(10);
			a.setEnergy(10);
			a.setDamage(3);
			b.setHit(10);
			b.setEnergy(10);
			b.setDamage(2);
			amount = 1;
			break;
		case 2:
		std::cout << "\033[2;35;40mCase " << i << "\033[0m\t\t"<< std::endl;
			a.setHit(10);
			a.setEnergy(10);
			a.setDamage(3);
			b.setHit(20);
			b.setEnergy(20);
			b.setDamage(3);
			c.setHit(10);
			c.setEnergy(10);
			c.setDamage(3);
			amount = 2;
			break;
		case 3:
		std::cout << "\033[2;35;40mCase " << i << "\033[0m\t\t"<< std::endl;
			a.setHit(0);
			a.setEnergy(-10);
			a.setDamage(10);
			b.setHit(10);
			b.setEnergy(-10);
			b.setDamage(0);
			amount = 10;
			break;
		case 4:
		std::cout << "\033[2;35;40mCase " << i << "\033[0m\t\t"<< std::endl;
			a.setHit(0);
			a.setEnergy(10);
			a.setDamage(10);
			b.setHit(10);
			b.setEnergy(10);
			b.setDamage(0);
			amount = -1;
			break;
	}
}

int main()
{
	ClapTrap a("Original");
	ScavTrap b("Target");
	FragTrap c("HighFive");
	DiamondTrap d("DiamondTrap");
	std::string input;
	int amount = 1;
	for (int i = 0; i < 5; i++){
		test(i, a, b, c, amount);
		if (amount <= 0){
			std::cerr << "We are not gonna fight forever!" <<std::endl;
			continue;
		}
		while(1){
			try{
				d.whoAmI();
				std::cout << "\033[2;33;40m"<< a.getName() << " has " << a.getHit() << " health points, " <<
				a.getEnergy() << " energy points, " << a.getDamage() << " damage points " << std::endl;
				std::cout << b.getName() << " has " << b.getHit() << " health points, " <<
				b.getEnergy() << " energy points, " << b.getDamage() << " damage points" << std::endl;		
				std::cout << c.getName() << " has " << c.getHit() << " health points, " <<
				c.getEnergy() << " energy points, " << c.getDamage() << " damage points \033[0m\t\t" << std::endl;		
				a.attack(b.getName());
				b.takeDamage(a.getDamage());
				b.beRepaired(amount);
				b.attack(a.getName());
				a.takeDamage(b.getDamage());
				a.beRepaired(amount);
				b.guardGate();
				c.attackRandomly(a, b);
				c.highFivesGuys();
				d.attack(c.getName());
				} catch (const char *message){break;}
		}
	}
	return 0;
}