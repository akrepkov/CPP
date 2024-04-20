/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:17:14 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/07 11:34:43 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Дочерний метод вызывается тогда, когда совпадает сигнатура 
(имя, типы параметров и является ли метод константным) 
и тип возврата дочернего метода с сигнатурой и типом возврата метода родительского класса. */

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Dog.hpp"

int main()
{
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\x1B[31mTypes are: \033[0m\t\t" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "\x1B[31mThe sounds are: \033[0m\t\t" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}
std:: cout << "\x1B[32m\tWrong Animal and Wrong Cat\033[0m\t\t" << std::endl;
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	const WrongDog* j = new WrongDog();
	const WrongCat* z = new WrongCat();
	std::cout << "\x1B[31mTypes are: \033[0m\t\t" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << z->getType() << " " << std::endl;
	std::cout << "\x1B[31mThe sounds are: \033[0m\t\t" << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	z->makeSound();
	std::cout << "\x1B[31mDelete \033[0m\t\t" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete z;
}
	return 0;
}

