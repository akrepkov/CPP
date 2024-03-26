/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:42:23 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 18:50:07 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	
	Zombie *ZombieArray = new Zombie[N];
	for (int i = 0; i < N; i++){
		ZombieArray[i].setname(name);
		ZombieArray[i].announce();
	}
	return (ZombieArray);
}
