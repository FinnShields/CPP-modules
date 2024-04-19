/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:14:58 by fshields          #+#    #+#             */
/*   Updated: 2024/04/12 12:13:45 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	FragTrap ft1("ft1");
	
	ft1.attack("everybody");
	ft1.highFivesGuys();

	FragTrap ft2("ft2");
	ft1.attack("ft2");
	ft2.takeDamage(30);
	
}