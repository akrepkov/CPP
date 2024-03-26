/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:32:44 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 19:02:53 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*    Pointer to Weapon: 
	Use when you want multiple Human instances to share the same weapon object and 
	modifications to the weapon object should affect all instances. 
	Be cautious about memory management.

    Reference to Weapon: 
	Use when you don't need to change the weapon object itself but want to share its properties among 
	multiple Human instances. It simplifies memory management and is safer, 
	but you can't change the actual object being referred to.*/

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
}
{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
}
return 0;
}
