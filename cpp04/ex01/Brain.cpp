/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:27:07 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/06 18:13:14 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain(){
	this->ideas = new std::string[100];
	std::cout << "\033[2;20;40m" <<  "Brain Constructor called\033[0m\t\t" << std::endl;
}

Brain::~Brain(){
	delete[] ideas;
	std::cout << "\033[2;20;40m" <<  "Brain Destructor called\033[0m\t\t" << std::endl;

}

Brain& Brain::operator=(const Brain &a){
	if (this == &a){
		return (*this);
	}
	std::cout << "\033[2;20;40m" <<  "Brain Assignment operator called\033[0m\t\t" << std::endl;
	delete[] ideas;
	if (a.ideas){
		this->ideas = new std::string[100];
		this->ideas = a.ideas;
	}
	else
		this->ideas = nullptr;	
	return (*this);
}

Brain::Brain(const Brain &a){
	std::cout << "\033[2;20;40m" <<  "Brain Copy constructor called\033[0m\t\t" << std::endl;
	if (a.ideas){
		this->ideas = new std::string[100];
		this->ideas = a.ideas;
	}
	else
		this->ideas = nullptr;	
}