/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:22:38 by fshields          #+#    #+#             */
/*   Updated: 2024/11/21 16:13:03 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv [])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"[inverted Polish expression]\"" << std::endl;
        return (EXIT_FAILURE);
    }
    try
    {
        std::string input(argv[1]);
        RPN rpn(input);
        rpn.calculate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (EXIT_SUCCESS);
}