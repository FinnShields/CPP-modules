/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:23:05 by fshields          #+#    #+#             */
/*   Updated: 2024/04/05 13:42:13 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie();
		Zombie( std::string );
		~Zombie();
		void	announce( void );
		void	init_zombie( std::string name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif