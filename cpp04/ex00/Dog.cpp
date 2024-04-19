/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:09:29 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 08:10:17 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog &c )
{
	*this = c;
	std::cout << "Dog copy constructor called" << std::endl;
}

void	Dog::operator=( const Dog &c )
{
	this->type = c.type;
	std::cout << "Dog assignment operator called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound()
{
	std::cout << "Woof!" << std::endl;
}