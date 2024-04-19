/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:45:50 by fshields          #+#    #+#             */
/*   Updated: 2024/04/11 11:29:10 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : value(0)
{}

Fixed::Fixed( const Fixed &f )
{
	*this = f;
}

Fixed::Fixed( const int value )
{
	this->value = (value << this->f_bits);
}

Fixed::Fixed( const float value )
{
	this->value = std::roundf(value * (1 << f_bits));
}

Fixed::~Fixed( void )
{}

void	Fixed::operator=( const Fixed &f )
{
	this->value = f.getRawBits();
}

bool	Fixed::operator<( const Fixed &f ) const
{
	return (this->value < f.value);
}

bool	Fixed::operator>( const Fixed &f ) const
{
	return (this->value > f.value);
}

bool	Fixed::operator<=( const Fixed &f ) const
{
	return (this->value <= f.value);
}

bool	Fixed::operator>=( const Fixed &f ) const
{
	return (this->value >= f.value);
}

bool	Fixed::operator==( const Fixed &f ) const
{
	return (this->value == f.value);
}

bool	Fixed::operator!=( const Fixed &f ) const
{
	return (this->value != f.value);
}

Fixed	Fixed::operator+(const Fixed &f ) const
{
	return (this->toFloat() + f.toFloat());
}

Fixed	Fixed::operator-(const Fixed &f ) const
{
	return (this->toFloat() - f.toFloat());
}

Fixed	Fixed::operator*(const Fixed &f ) const
{
	return (this->toFloat() * f.toFloat());
}

Fixed	Fixed::operator/(const Fixed &f ) const
{
	return (this->toFloat() / f.toFloat());
}

Fixed&	Fixed::operator++( void )
{
	++this->value;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed temp = *this;
	this->value ++;
	return (temp);
}

Fixed&	Fixed::operator--( void )
{
	--this->value;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed temp = *this;
	this->value --;
	return (temp);
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

Fixed&	Fixed::min( Fixed& f1, Fixed& f2)
{
	if (f1 <= f2)
		return (f1);
	else
		return (f2);	
}

Fixed&	Fixed::max( Fixed& f1, Fixed& f2)
{
	if (f1 >= f2)
		return (f1);
	else
		return (f2);	
}

const Fixed&	Fixed::min( const Fixed& f1, const Fixed& f2)
{
	if (f1 <= f2)
		return (f1);
	else
		return (f2);	
}

const Fixed&	Fixed::max( const Fixed& f1, const Fixed& f2)
{
	if (f1 >= f2)
		return (f1);
	else
		return (f2);	
}