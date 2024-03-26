/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:38:24 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 15:46:52 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	int	i = 0;
	std::string input;
	while(input != "EXIT"){
		std::cout << "\033[1;31mEnter one of the commands: ADD, SEARCH or EXIT\033[0m"<< std::endl;
		std::cin >> input;
		if (std::cin.fail())
			return (1);
		if (input.compare("ADD") == 0 || input.compare("1") == 0){
			phonebook.AddContact(i);
			i = (i + 1) % 8;
		}
		else if (input.compare("SEARCH") == 0 || input.compare("2") == 0)
			phonebook.DisplayContact(phonebook);
		else if (input != "EXIT")
			std::cout << "Invalid input" << std::endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			return (1);
		}
	}
	return 0;
}

/*	while (1)
	{
		std::cout << "Enter your age: ";
		std::cin >> nAge;
 
		if (std::cin.fail()) // если никакого извлечения не произошло
		{
			std::cin.clear(); // то сбрасываем все текущие флаги состояния и устанавливаем goodbit, чтобы иметь возможность использовать функцию ignore()
			std::cin.ignore(32767, '\n'); // очищаем поток от мусора
			continue; // просим пользователя ввести свой возраст еще раз
		}
 
		std::cin.ignore(32767, '\n'); // очищаем весь мусор, который остался в потоке после извлечения
		if (std::cin.gcount() > 1) // если мы очистили более одного символа
			continue; // то этот ввод считается некорректным, и мы просим пользователя ввести свой возраст еще раз
 
		if (nAge <= 0) // убеждаемся, что nAge является положительным числом
			continue;
 
		break;
	}*/
