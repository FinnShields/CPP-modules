/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:32:43 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 08:42:48 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal( std::string type );
	WrongAnimal( const WrongAnimal &a );
	void	operator=( const WrongAnimal &a );
	virtual ~WrongAnimal();
	std::string	getType();
	virtual void	makeSound();
};

#endif