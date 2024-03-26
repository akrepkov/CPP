/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:38:29 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 17:59:40 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include <iomanip>
#include <iostream>

class Weapon{
	private:
		std::string _type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		std::string &getType();
		void setType(std::string type);

};

#endif