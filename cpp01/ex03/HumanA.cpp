/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 08:54:22 by fshields          #+#    #+#             */
/*   Updated: 2024/04/08 10:23:58 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &type ) : name(name), type(type)
{}

HumanA::~HumanA( void )
{}

void HumanA::attack( void )
{
	std::cout << this->name << " attacks with their " << type.getType() << std::endl;
}