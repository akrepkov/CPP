/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:06:23 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/08 13:37:56 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::~Serializer() {
}

Serializer& Serializer::operator=(const Serializer& copy) {
	if (this != &copy) {
		return *this;
	}
    return *this;
}

Serializer::Serializer(const Serializer& copy) {
	*this = copy;
}

uintptr_t Serializer::serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}