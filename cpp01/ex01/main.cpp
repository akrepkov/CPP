/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:16:02 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 18:56:08 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	int N[] = {0, -1, 1, 5};
	for (int i = 0; i < 4; i++){
		std::cout << "\033[1;31mTEST: N= \033[0m" << N[i] << std::endl;
		if (N[i] >= 0){
			Zombie *ZombieArray = zombieHorde(N[i], "Zombie");
			delete[] ZombieArray;
		}
		else
			std::cout << "Wrong amount" << std::endl;
	}
	return 0;
}