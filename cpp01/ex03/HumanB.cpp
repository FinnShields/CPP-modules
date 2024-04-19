/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 08:54:10 by fshields          #+#    #+#             */
/*   Updated: 2024/04/08 10:52:21 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name(name)
{}

HumanB::~HumanB( void )
{}

void	HumanB::attack( void )
{
	if (this->type != NULL)
		std::cout << this->name << " attacks with their " << type->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon!" << std::endl;
}

void	HumanB::setWeapon( Weapon& type )
{
	this->type = &type;
}