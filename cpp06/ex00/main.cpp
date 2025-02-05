/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:51:03 by fshields          #+#    #+#             */
/*   Updated: 2024/10/24 08:09:34 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "Error: no argument provided" << std::endl;
        return (EXIT_FAILURE);
    }
    if (argc > 2)
    {
        std::cerr << "Error: too many arguments provided" << std::endl;
        return (EXIT_FAILURE);
    }
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Woah, the input was *way* out of whack! (" << e.what() << ")" << std::endl;
    }
    return (EXIT_SUCCESS);
}