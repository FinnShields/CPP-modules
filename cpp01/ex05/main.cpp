/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:04:34 by fshields          #+#    #+#             */
/*   Updated: 2024/04/10 08:23:59 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main ( void )
{
	std::string input;
	Harl harl;

	while (true)
	{
		std::cout << "Options: DEBUG, INFO, WARNING, ERROR" << std::endl;
		std::cout << "> ";
		std::cin >> input;
		std::cout << "Harl: ";
		harl.complain(input);
	}
}