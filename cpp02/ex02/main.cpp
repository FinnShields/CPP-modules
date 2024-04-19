/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:45:47 by fshields          #+#    #+#             */
/*   Updated: 2024/04/11 11:45:17 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	
	Fixed a;
	Fixed b(42.42f);
	std::cout << "a = " << a.toFloat() << " and b = " << b.toFloat() << std::endl;
	std::cout << "(a < b)? ";
	if (a < b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "(a > b)? ";
	if (a > b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "(a == b)? ";
	if (a == b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "(a != b)? ";
	if (a != b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "a is still " << a++ << std::endl;
	std::cout << "now it's " << a << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "Which value the max? Of course, it's " << Fixed::max(a, b) << std::endl;
	std::cout << "So the min is, you guessed it, " << Fixed::min(a, b) << std::endl;
	return 0;
}