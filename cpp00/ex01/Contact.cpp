/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:45:49 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/13 14:28:18 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

/*Setters*/
void Contact::setFirstName(std::string firstName){
	_firstName = firstName;
}

void Contact::setLastName(std::string lastName){
	_lastName = lastName;
}

void Contact::setNickName(std::string nickName){
	_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber){
	_phoneNumber = phoneNumber;
}

void Contact::setDarkSecret(std::string darkSecret){
	_darkSecret = darkSecret;
}

/*Getters*/
std::string Contact::getFirstName(){
	return (_firstName);
}

std::string Contact::getLastName(){
	return (_lastName);
}

std::string Contact::getNickName(){
	return (_nickName);
}

std::string Contact::getPhoneNumber(){
	return (_phoneNumber);
}

std::string Contact::getDarkSecret(){
	return (_darkSecret);
}

void Contact::AdjustLength(std::string str){
	if (str.length() > 9){
		str.resize(9);
		str.append(1, '.');
	}
	std::cout << std::right << std::setw(10) << str;
}

void Contact::AdjustSubString(Contact Contact){
	AdjustLength(Contact._firstName);
	std::cout <<  " | ";
	AdjustLength(Contact._lastName);
	std::cout <<  " | ";
	AdjustLength(Contact._nickName);
	std::cout << std::endl;
}