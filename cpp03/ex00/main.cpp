/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:14:58 by fshields          #+#    #+#             */
/*   Updated: 2024/04/12 08:28:45 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap trap1 = ClapTrap("trap1");
	trap1.attack("you");
	ClapTrap trap2 = ClapTrap("trap2");
	trap2.attack("trap1");
	trap1.takeDamage(0);
	trap1.beRepaired(10);
	trap2.takeDamage(8);
	trap2.beRepaired(10);
	ClapTrap trap3(trap2);
	ClapTrap trap4;
	trap4 = trap3;
}