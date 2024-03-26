/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:34:23 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/13 14:26:53 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

class PhoneBook{
	private:
	Contact _newContact[8];

	public:
	void AddContact(int i);
	void SearchContact(int max);
	void DisplayContact(PhoneBook phonebook);
};

#endif