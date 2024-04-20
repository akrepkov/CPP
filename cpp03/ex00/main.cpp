/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:54 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 16:46:07 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Original");
	ClapTrap b("Target");
	int amount = 2;
	a.setObj(&b);
	b.setObj(&a);
	a.setDamage(amount);
	b.setDamage(amount);
	while(1){
		try{
		a.attack(b.getName());
		b.attack(a.getName());
		a.beRepaired(amount);
		b.beRepaired(amount);
		} catch (const char *message){
		return 0;
		}
	}
	return 0;
}