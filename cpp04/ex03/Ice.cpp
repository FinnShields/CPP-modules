/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:55:06 by fshields          #+#    #+#             */
/*   Updated: 2024/04/17 10:01:44 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& i): AMateria(i.type)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& i)
{
	std::cout << "Ice assignment operator called" << std::endl;
	this->type = i.type;
	return (*this);
}
Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice* Ice::clone() const
{
	Ice* newIce = new Ice();
	return (newIce);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}