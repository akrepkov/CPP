/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:54 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 16:47:49 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void test(int i, ClapTrap &a, ScavTrap &b){
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
			break;
		case 2:
		std::cout << "\033[2;35;40mCase " << i << "\033[0m\t\t"<< std::endl;
			a.setHit(10);
			a.setEnergy(10);
			a.setDamage(10);
			b.setHit(20);
			b.setEnergy(20);
			b.setDamage(20);
			break;
		case 3:
		std::cout << "\033[2;35;40mCase " << i << "\033[0m\t\t"<< std::endl;
			a.setHit(0);
			a.setEnergy(-10);
			a.setDamage(10);
			b.setHit(10);
			b.setEnergy(-10);
			b.setDamage(0);
			break;
	}
}

int main()
{
	ClapTrap a("Original");
	ScavTrap b("Target");
	for (int i = 0; i < 4; i++){
		test(i, a, b);
		while(1){
			try{
				std::cout << "\033[2;33;40m"<< a.getName() << " has " << a.getHit() << " health points, " <<
				a.getEnergy() << " energy points, " << a.getDamage() << " damage points " << std::endl;
				std::cout << b.getName() << " has " << b.getHit() << " health points, " <<
				b.getEnergy() << " energy points, " << b.getDamage() << " damage points \033[0m\t\t" << std::endl;		
				a.attack(b.getName());
				b.takeDamage(a.getDamage());
				b.beRepaired(1);
				b.attack(a.getName());
				a.takeDamage(b.getDamage());
				a.beRepaired(1);
				b.guardGate();
				} catch (const char *message){break;}
		}
	}
	return 0;
}