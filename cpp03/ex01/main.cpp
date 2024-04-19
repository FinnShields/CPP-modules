/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:14:58 by fshields          #+#    #+#             */
/*   Updated: 2024/04/12 09:56:43 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap scav1("scav1");
	ScavTrap scav2("scav2");

	scav1.attack("scav2");
	scav2.takeDamage(20);
	scav2.beRepaired(10);
	scav1.guardGate();
}