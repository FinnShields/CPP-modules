/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:08:49 by fshields          #+#    #+#             */
/*   Updated: 2024/04/17 10:00:59 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;

}

Cure::Cure(const Cure& i): AMateria(i.type)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& i)
{
	std::cout << "Cure assignment operator called" << std::endl;
	this->type = i.type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const
{
	Cure* newCure = new Cure();
	return (newCure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "Cure: * heals " << target.getName() << "'s wounds *" << std::endl;
}