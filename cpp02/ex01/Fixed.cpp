/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:46:55 by fshields          #+#    #+#             */
/*   Updated: 2024/04/11 09:37:05 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &f )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (value << this->f_bits);
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	this->value = std::roundf(value * (1 << f_bits));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::operator=( const Fixed &f )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = f.getRawBits();
}

std::ostream&	operator<<( std::ostream &os, const Fixed &f )
{
	os << f.toFloat();
	return (os);
}

int	Fixed::getRawBits( void ) const
{
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

int	Fixed::toInt( void ) const
{
	return (value >> f_bits);
}

float	Fixed::toFloat( void ) const
{
	return ((float) value / (float) (1 << f_bits));
}