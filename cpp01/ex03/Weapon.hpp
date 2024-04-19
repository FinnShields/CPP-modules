/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 08:44:33 by fshields          #+#    #+#             */
/*   Updated: 2024/04/08 10:26:23 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
# define WEAPON

# include <string>
# include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon( std::string type );
		~Weapon( void );
		const std::string& getType( void );
		void setType( std::string newType );
};

#endif