/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:17:14 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/07 11:39:52 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() /*Abstract classes cannot be instantiated on their own because they contain pure virtual methods, 
which don't have a concrete implementation in the base class. */
{
	const Animal* animal[10];
	for (int i = 0; i < 10; i++){
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		(animal[i])->makeSound();
	}
	for (int i = 0; i < 10; i++){
		delete animal[i];
	}
	{
		std::cout << "\nCreating new cats and dogs" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "Deleting cats and dogs" << std::endl;
		delete j;//should not create a leak
		delete i;
	}
	{
		std::cout << "\033[2;33;20mCreating a cat and a dog\033[0m\t\t" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	return 0;
}

