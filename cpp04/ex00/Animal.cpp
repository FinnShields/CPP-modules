/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 07:52:49 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 08:29:17 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( std::string type ) : type(type)
{
	std::cout << "Animal string constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal( const Animal &a )
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = a;
}


void	Animal::operator=( const Animal &a )
{
	this->type = a.type;
	std::cout << "Animal assignment operator called" << std::endl;
}

std::string	Animal::getType()
{
	return (this->type);
}

void	Animal::makeSound()
{
	std::cout << "Generic animal sounds!" << std::endl;
}