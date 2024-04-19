/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:24:03 by fshields          #+#    #+#             */
/*   Updated: 2024/04/17 09:59:28 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : name(name) 
{
	std::cout << "Character string constructor called" << std::endl;
	for(int i = 0; i < 4; i ++)
		this->array[i] = nullptr;
}

Character::Character(const Character& c)
{
	*this = c;
	std::cout << "Character copy constructor called" << std::endl;

}

Character& Character::operator=(const Character& c)
{
	std::cout << "Character assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (array[i] != nullptr)
			delete (array[i]);
	for(int i = 0; i < 4; i++)
		this->array[i] = c.array[i]->clone();
	this->name = c.getName();
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (array[i] != nullptr)
			delete (array[i]);
}

std::string const & Character::getName() const 
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;
	while (i < 4 && this->array[i] != nullptr)
		i ++;
	if (i == 4)
		return ;
	this->array[i] = m;
}

void	Character::unequip(int idx)
{
	if (this->array[idx] != nullptr)
		this->array[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target)
{
	this->array[idx]->use(target);
}