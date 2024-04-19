/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:08:33 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 09:16:26 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	protected:
		std::string type;
		Brain *brain;
	public:
		Dog();
		Dog( const Dog &c );
		void	operator=( const Dog &c );
		~Dog();
		void	makeSound();
};

#endif