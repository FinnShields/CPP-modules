/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:13:39 by fshields          #+#    #+#             */
/*   Updated: 2024/04/05 13:50:57 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{}

PhoneBook::~PhoneBook()
{}

void PhoneBook::add_contact( Contact newContact )
{
	int i;

	i = newContact.get_index();
	this->contacts[i] = newContact;
}

void PhoneBook::display_all()
{
	int	i = 0;
	while (i < 8)
	{
		if (this->contacts[i].get_first_name().compare("\0") != 0)
			this->contacts[i].display();
		i ++;
	}
}

void PhoneBook::search( std::string index )
{
	int	i;
	
	i = atoi(&index.at(0));
	if (index.length() != 1 || !isdigit(index.at(0)) || i < 0 || i > 7)
		std::cerr << "Invalid index." << std::endl;
	else if (this->contacts[i].get_first_name().compare("\0") == 0)
		std::cerr << "No contact stored at that index." << std::endl;
	else
		this->contacts[i].display_full();
}