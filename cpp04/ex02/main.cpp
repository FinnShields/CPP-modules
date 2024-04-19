/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:11:15 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 10:37:18 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	AAnimal *array[10];

	for (int i = 0; i < 5; i++)
		array[i] = new Cat();
	for (int i = 5; i < 10; i++)
		array[i] = new Dog();
	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat(*cat1);
	std::cout << "Addr of Cat1's brain: " << cat1->getBrainAddr() << std::endl;
	std::cout << "Addr of Cat2's brain: " << cat2->getBrainAddr() << std::endl;
	delete (cat1);
	delete (cat2);
	for (int i = 0; i < 10; i++)
		delete array[i];
}