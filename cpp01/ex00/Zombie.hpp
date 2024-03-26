/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:58:46 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 18:34:26 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iomanip>
#include <iostream>

class Zombie{
	private:
	std::string name;

	public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce();
};

Zombie*		newZombie( std::string name );
void		randomChump( std::string name );


#endif

/*If the zombie's scope is limited to a specific function or block, 
stack allocation is usually more appropriate. 
If the zombie needs to persist beyond the scope in which it's created, 
heap allocation is necessary.*/