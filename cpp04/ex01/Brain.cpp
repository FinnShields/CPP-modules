/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:06:57 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 09:15:13 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" <<  std::endl;
}

Brain::Brain ( const Brain &b )
{
	*this = b;
	std::cout << "Brain copy contructor called" << std::endl;
}

void	Brain::operator=( const Brain &b )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	std::cout << "Brain assignment operator called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}