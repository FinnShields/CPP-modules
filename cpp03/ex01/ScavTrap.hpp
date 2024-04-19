/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:35:11 by fshields          #+#    #+#             */
/*   Updated: 2024/04/12 09:41:13 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& st );
		void	operator=( const ScavTrap& st );
		~ScavTrap();
		void	guardGate( void );
		void	attack( std::string target );
};

#endif