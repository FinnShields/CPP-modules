/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:03:55 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 10:38:27 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat")
{
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat &c )
{
	*this = c;
	std::cout << "Cat copy constructor called" << std::endl;
}

void	Cat::operator=( const Cat &c )
{
	this->type = c.type;
	this->brain = new Brain();
	*(this->brain) = *(c.brain);
	std::cout << "Cat assignment operator called" << std::endl;
}

Cat::~Cat()
{
	delete (this->brain);
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound()
{
	std::cout << "Meeeooooow!" << std::endl;
}

void	*Cat::getBrainAddr()
{
	return (this->brain);
}