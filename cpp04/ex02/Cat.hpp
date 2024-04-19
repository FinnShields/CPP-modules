/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:01:29 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 10:37:47 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
	protected:
		std::string type;
		Brain *brain;
	public:
		Cat();
		Cat( const Cat &c );
		void	operator=( const Cat &c );
		~Cat();
		void	makeSound();
		void	*getBrainAddr();
};

#endif