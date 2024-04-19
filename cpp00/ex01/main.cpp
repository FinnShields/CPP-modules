/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 09:22:09 by fshields          #+#    #+#             */
/*   Updated: 2024/04/04 12:24:57 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
// #include <iostream>

int main()
{
	std::string input;
	int	i = 0;
	PhoneBook book;
	while (true)
	{
		std::cout << "Options: ADD, SEARCH, EXIT " << std::endl << "> ";
		std::cin >> input;
		if (input.empty())
			exit(0);
		if (input.compare("ADD") == 0)
		{
			Contact newContact(i);
			book.add_contact(newContact);
			i ++;
			if (i == 8)
				i = 0;
		}
		else if (input.compare("SEARCH") == 0)
		{
			book.display_all();
			std::cout << "Select index (0-7): ";
			std::cin >> input;
			book.search(input);
		}
		else if (input.compare("EXIT") == 0)
			return (0);
	}
}