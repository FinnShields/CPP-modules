/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:46:38 by fshields          #+#    #+#             */
/*   Updated: 2024/04/11 09:35:13 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					value;
		static const int	f_bits = 8;
	public:
		Fixed( void );
		Fixed ( const Fixed &f );
		Fixed( const int value );
		Fixed( const float value );
		~Fixed( void );
		void 	operator=( const Fixed &f );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

std::ostream&	operator<<( std::ostream &os, const Fixed &f );

#endif