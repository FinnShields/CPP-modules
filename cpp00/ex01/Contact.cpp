/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 08:50:35 by fshields          #+#    #+#             */
/*   Updated: 2024/04/05 13:50:32 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "\0";
}

Contact::Contact( int i )
{
	std::cout << "Enter first name: ";
	std::cin >> this->first_name;
	std::cout << "Enter last name: ";
	std::cin >> this->last_name;
	std::cout << "Enter nick name: ";
	std::cin >> this->nick_name;
	std::cout << "Enter phone number: ";
	std::cin >> this->number;
	std::cout << "Enter darkest secret: ";
	std::cin >> this->dark_secret;
	this->index = i;
}

Contact::~Contact()
{}

void	Contact::set_index( int i )
{
	this->index = i;
}

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

int		Contact::get_index()
{
	return (this->index);
}

static void	display_one( std::string str )
{
	int	i = 0;
	
	if (str.length() < 10)
		std::cout << std::setw(10) << str;
	else if (str.length() == 10)
		std::cout << str;
	else
	{
		while (i < 9)
			std::cout << str.at(i++);
		std::cout << ".";
	}
}

void	Contact::display()
{
	std::cout << "         " << this->index << "|";
	display_one(this->first_name);
	std::cout << "|";
	display_one(this->last_name);
	std::cout << "|";
	display_one(this->nick_name);
	std::cout << std::endl;
};

void Contact::display_full()
{
	std::cout << this->first_name << std::endl;
	std::cout << this->last_name << std::endl;
	std::cout << this->nick_name << std::endl;
	std::cout << this->number << std::endl;
	std::cout << this->dark_secret << std::endl;
}