/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:45:38 by fshields          #+#    #+#             */
/*   Updated: 2024/04/11 11:29:22 by fshields         ###   ########.fr       */
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
		bool	operator<( const Fixed &f ) const;
		bool	operator>( const Fixed &f ) const;
		bool	operator<=( const Fixed &f ) const;
		bool	operator>=( const Fixed &f ) const;
		bool	operator==( const Fixed &f ) const;
		bool	operator!=( const Fixed &f ) const;
		Fixed	operator+(const Fixed &f ) const;
		Fixed	operator-(const Fixed &f ) const;
		Fixed	operator*(const Fixed &f ) const;
		Fixed	operator/(const Fixed &f ) const;
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		static Fixed&	min( Fixed& f1, Fixed& f2);
		static const Fixed&	min( const Fixed& f1, const Fixed& f2);
		static Fixed&	max( Fixed& f1, Fixed& f2);
		static const Fixed&	max( const Fixed& f1, const Fixed& f2);
};

std::ostream&	operator<<( std::ostream &os, const Fixed &f );

#endif