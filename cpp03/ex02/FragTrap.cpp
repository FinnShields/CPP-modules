/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:05:08 by fshields          #+#    #+#             */
/*   Updated: 2024/04/12 12:12:26 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor used" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap string constructor used" << std::endl;
}

FragTrap::FragTrap( const FragTrap& ft ) : ClapTrap(ft.name)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

void	FragTrap::operator=( const FragTrap& ft )
{
	this->name = ft.name;
	this->attack_damage = ft.attack_damage;
	this->hit_points = ft.hit_points;
	this->energy_points = ft.energy_points;
	std::cout << "ScavTrap assignment operator used" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor used" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << name << ": Hey, how about a high five? Anybody?!" << std::endl;
}