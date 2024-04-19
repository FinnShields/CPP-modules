/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 07:51:59 by fshields          #+#    #+#             */
/*   Updated: 2024/04/15 10:36:27 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal
{
protected:
	std::string type;
	AAnimal();
	AAnimal( std::string type );
	AAnimal( const AAnimal &a );
public:
	virtual ~AAnimal();
	void	operator=( const AAnimal &a );
	std::string	getType();
	virtual void	makeSound() = 0;
	virtual void	*getBrainAddr() = 0;
};

#endif