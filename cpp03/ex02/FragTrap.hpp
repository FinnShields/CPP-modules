/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:02:36 by fshields          #+#    #+#             */
/*   Updated: 2024/04/12 12:07:21 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRAG_TRAP
# define FRAG_TRAP
# include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap( std::string name );
		FragTrap( const FragTrap& ft );
		void	operator=( const FragTrap& ft );
		~FragTrap();
		void	highFivesGuys( void );
};


#endif