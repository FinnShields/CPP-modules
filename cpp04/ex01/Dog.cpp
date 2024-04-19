/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:09:29 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 09:21:18 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog &d )
{
	*this = d;
	std::cout << "Dog copy constructor called" << std::endl;
}

void	Dog::operator=( const Dog &d )
{
	this->type = d.type;
	this->brain = new Brain();
	this->brain = d.brain;
	std::cout << "Dog assignment operator called" << std::endl;
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound()
{
	std::cout << "Woof!" << std::endl;
}