/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:52:22 by fshields          #+#    #+#             */
/*   Updated: 2024/04/05 12:18:36 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie* zombie = newZombie("Zombie 1");

	zombie->announce();
	delete(zombie);
	randomChump("Zombie 2");
}