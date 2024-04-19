/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:01:29 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 08:05:36 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	protected:
		std::string type;
	public:
		Cat();
		Cat( const Cat &c );
		void	operator=( const Cat &c );
		~Cat();
		void	makeSound();
};

#endif