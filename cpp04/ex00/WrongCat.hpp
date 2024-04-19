/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:36:04 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 08:36:34 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongCat();
		WrongCat( const WrongCat &c );
		void	operator=( const WrongCat &c );
		~WrongCat();
		void	makeSound();
};

#endif