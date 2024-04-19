/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:32:02 by fshields          #+#    #+#             */
/*   Updated: 2024/04/12 12:00:38 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &ct )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ct;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor constructor called" << std::endl;
}

void	ClapTrap::operator=( const ClapTrap &ct )
{
	this->name = ct.name;
	this->hit_points = ct.hit_points;
	this->energy_points = ct.energy_points;
	this->attack_damage = ct.attack_damage;
	std::cout << "Assignment operator called" << std::endl;
}

void	ClapTrap::attack( const std::string& target )
{
	if (hit_points == 0)
		std::cout << "ClapTrap " << name << " has no hit points left :(" << std::endl;
	else if (energy_points == 0)
		std::cout << "ClapTrap " << name << " has no energy points left :(" << std::endl;
	else 
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	if (hit_points && energy_points)
		energy_points --;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	int	old_hp;
	
	if (!amount)
		return ;
	old_hp = hit_points;
	while (hit_points && (amount-- > 0))
		hit_points --;
	std::cout << "ClapTrap " << name << " was attacked and lost " << old_hp - hit_points << " hit points!" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int	amount )
{
	int	old_hp;

	
	if (!amount)
		return ;
	old_hp = hit_points;
	if (!energy_points)
		std::cout << "ClapTrap " << name << " has no energy points left :(" << std::endl;
	else
	{
		hit_points += amount;
		energy_points--;
		std::cout << "ClapTrap " << name << " was repaired and gained " << hit_points - old_hp << " hit points!" << std::endl;
	}
}

