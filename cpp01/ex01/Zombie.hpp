/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:58:46 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/08 16:04:27 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib> 

class Zombie{
	private:
	std::string name;

	public:
	void announce();
	Zombie();
	~Zombie();
	Zombie(std::string name);
	void setname(std::string name);
};

Zombie* zombieHorde( int N, std::string name );


#endif
