/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:17:14 by akrepkov          #+#    #+#             */
/*   Updated: 2024/04/07 11:37:34 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Dog.hpp"

int main()
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
	/*Test 1*/
	{
		std::cout << "\033[2;33;20mCreating new cats and dogs\033[0m\t\t" << std::endl;
		const Animal* i = new Cat();
		{
			const Animal* z = i;
			z->makeSound();
		}
		std::cout << "\033[2;33;20mDeleting cats and dogs\033[0m\t\t" << std::endl;
		i->makeSound();
		delete i;
	}
	/*Test 2*/
	{
		std::cout << "\033[2;33;20mCreating a cat and a dog\033[0m\t\t" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	return 0;
}

