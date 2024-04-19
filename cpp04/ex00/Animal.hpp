/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 07:51:59 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 08:42:38 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal( std::string type );
	Animal( const Animal &a );
	void	operator=( const Animal &a );
	virtual ~Animal();
	std::string	getType();
	virtual void	makeSound();
};

#endif