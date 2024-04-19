/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:35:03 by fshields          #+#    #+#             */
/*   Updated: 2024/04/12 09:44:24 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	std::cout << "ScavTrap default constructor used" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap string constructor used" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& st ) : ClapTrap(st.name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

void	ScavTrap::operator=( const ScavTrap& st )
{
	this->name = st.name;
	this->attack_damage = st.attack_damage;
	this->hit_points = st.hit_points;
	this->energy_points = st.energy_points;
	std::cout << "ScavTrap assignment operator used" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor used" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack( std::string target )
{
	if (!hit_points)
		std::cout << "ScavTrap " << name << " has no hp left :(" << std::endl;
	else if (!energy_points)
		std::cout << "ScavTrap " << name << " has no energy left :(" << std::endl;
	else
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}