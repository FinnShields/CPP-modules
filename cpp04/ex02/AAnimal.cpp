/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 07:52:49 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 10:37:09 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal( std::string type ) : type(type)
{
	std::cout << "AAnimal string constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal &a )
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = a;
}


void	AAnimal::operator=( const AAnimal &a )
{
	this->type = a.type;
	std::cout << "AAnimal assignment operator called" << std::endl;
}

std::string	AAnimal::getType()
{
	return (this->type);
}

void	AAnimal::makeSound()
{
	std::cout << "Generic AAnimal sounds!" << std::endl;
}

void	*AAnimal::getBrainAddr()
{
	return (nullptr);
}