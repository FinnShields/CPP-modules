/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:04:34 by fshields          #+#    #+#             */
/*   Updated: 2024/04/10 08:21:23 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main ( int argc, char *argv[] )
{
	Harl harl;
	std::string input;

	if (argc != 2)
		return (0);
	input = argv[1];
	if (!input.compare("DEBUG"))
		harl.complain(0);
	else if (!input.compare("INFO"))
		harl.complain(1);
	else if (!input.compare("WARNING"))
		harl.complain(2);
	else if (!input.compare("ERROR"))
		harl.complain(3);
	else
		harl.complain(-1);
	return (0);
}