/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:23:06 by fshields          #+#    #+#             */
/*   Updated: 2024/04/17 10:02:44 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for(int i = 0; i < 4; i ++)
		this->array[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& ms)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = ms;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms)
{
	std::cout << "MateriaSource assignment constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->array[i] != nullptr)
			delete (this->array[i]);
	for (int i = 0; i < 4; i++)
		this->array[i] = ms.array[i]->clone();
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->array[i] != nullptr)
			delete (this->array[i]);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;
	while (i < 4 && this->array[i] != nullptr)
		i ++;
	if (i == 4)
		return ;
	this->array[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i ++)
		if (this->array[i] && this->array[i]->getType().compare(type) == 0)
			return (this->array[i]->clone());
	return (0);
}