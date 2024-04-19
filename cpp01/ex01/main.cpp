/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:31:29 by fshields          #+#    #+#             */
/*   Updated: 2024/04/05 13:41:50 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	int	zombieNo = 6;
	int	i = 0;
	Zombie*	horde = zombieHorde(zombieNo, "Zomb");

	while (i < zombieNo)
		horde[i++].announce();
	i = 0;
	delete [] horde;
}