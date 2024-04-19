/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:53:24 by fshields          #+#    #+#             */
/*   Updated: 2024/04/11 08:40:55 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					value;
		static const int	f_bits = 8;
	public:
		Fixed( void );
		Fixed( Fixed &f );
		void 	operator=( Fixed &f );
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif