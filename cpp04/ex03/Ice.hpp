/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:41:56 by fshields          #+#    #+#             */
/*   Updated: 2024/04/16 13:12:15 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
	private:
		std::string type;
	public:
		Ice();
		Ice(const Ice& i);
		Ice& operator=(const Ice& i);
		~Ice();
		Ice* clone() const;
		void use(ICharacter& target);
};
#endif