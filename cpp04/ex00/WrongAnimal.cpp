/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:33:26 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 08:34:05 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type(type)
{
	std::cout << "WrongAnimal string constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &a )
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = a;
}


void	WrongAnimal::operator=( const WrongAnimal &a )
{
	this->type = a.type;
	std::cout << "WrongAnimal assignment operator called" << std::endl;
}

std::string	WrongAnimal::getType()
{
	return (this->type);
}

void	WrongAnimal::makeSound()
{
	std::cout << "Generic WrongAnimal sounds!" << std::endl;
}