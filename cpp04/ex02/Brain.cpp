/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:27:07 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/03 13:13:42 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain(){

}

Brain::~Brain(){

}

Brain& Brain::operator=(const Brain &a){
	if (this != &a){
		
	}
	return (*this);
}

Brain::Brain(const Brain &a){
	*this = a;
}