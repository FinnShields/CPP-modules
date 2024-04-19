/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:17:06 by fshields          #+#    #+#             */
/*   Updated: 2024/04/16 13:12:05 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* array[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ms);
		MateriaSource& operator=(const MateriaSource& ms);
		~MateriaSource();
		void	learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif