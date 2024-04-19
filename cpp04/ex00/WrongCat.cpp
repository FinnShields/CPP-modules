/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:35:04 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 08:36:44 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat &c )
{
	*this = c;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

void	WrongCat::operator=( const WrongCat &c )
{
	this->type = c.type;
	std::cout << "WrongCat assignment operator called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound()
{
	std::cout << "Woof!" << std::endl;
}