/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:08:33 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 10:37:44 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
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
		void	*getBrainAddr();
};

#endif