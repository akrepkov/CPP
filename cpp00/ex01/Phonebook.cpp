/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:57:12 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/13 14:28:15 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

void PhoneBook::AddContact (int i){
	std::string input;

	std::cout << "Enter First Name: " << std::endl;
	std::cin >> input;
	_newContact[i].setFirstName(input);
	std::cout << "Enter Last Name: " << std::endl;
	std::cin >> input;
	_newContact[i].setLastName(input);
	std::cout << "Enter Nick Name: " << std::endl;
	std::cin >> input;
	_newContact[i].setNickName(input);
	std::cout << "Enter Phone Number: " << std::endl;
	std::cin >> input;
	_newContact[i].setPhoneNumber(input);
	std::cout << "Enter Dark Secret: " << std::endl;
	std::cin >> input;
	_newContact[i].setDarkSecret(input);	
}

void PhoneBook::SearchContact(int max)
{
	int index;
	std::cout << "Enter The Index: ";
	std::cin >> index;
	if (std::cin.fail() || index <= 0 || index > max)
	{
		std::cout << "Wrong input" << std::endl;
		return;
	}
	index--;
	std::cout << std::left << index + 1 << std::endl;
	std::cout << std::left << _newContact[index].getFirstName() << std::endl;
	std::cout << std::left << _newContact[index].getLastName() << std::endl;
	std::cout << std::left << _newContact[index].getNickName() << std::endl;
	std::cout << std::left << _newContact[index].getPhoneNumber() << std::endl;
	std::cout << std::left << _newContact[index].getDarkSecret() << std::endl;
}

void PhoneBook::DisplayContact(PhoneBook phonebook)
{
	int max;
	std::cout << std::right << std::setw(10) << "Index"
			  << " | " << std::setw(10) << "First Name"
			  << " | " << std::setw(10) << "Last Name"
			  << " | " << std::setw(10) << "Nick Name" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!(phonebook._newContact[i].getFirstName()).empty())
		{
			std::cout << std::right << std::setw(10) << i + 1 << " | ";
			_newContact[i].AdjustSubString(phonebook._newContact[i]);
			max = i + 1;
		}
	}
	phonebook.SearchContact(max);
}

