/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 08:44:20 by fshields          #+#    #+#             */
/*   Updated: 2024/04/08 10:25:17 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : type(type)
{}

Weapon::~Weapon( void )
{}

const std::string& Weapon::getType( void )
{
	return (type);
}

void Weapon::setType( std::string newType )
{
	this->type = newType;
}
