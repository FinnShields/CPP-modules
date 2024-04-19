/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:08:26 by fshields          #+#    #+#             */
/*   Updated: 2024/04/16 13:17:08 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	private:
		std::string type;
	public:
		Cure();
		Cure(const Cure& i);
		Cure& operator=(const Cure& i);
		~Cure();
		Cure* clone() const;
		void use(ICharacter& target);
};
#endif