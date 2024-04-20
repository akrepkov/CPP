/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:39:46 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/30 10:48:58 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name); //ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& a);
		DiamondTrap(const DiamondTrap &a);
		void whoAmI();
		void attack(const std::string& target);
};

#endif