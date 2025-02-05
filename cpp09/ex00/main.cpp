/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:10:47 by fshields          #+#    #+#             */
/*   Updated: 2024/11/19 14:43:38 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: ./btc [path_to_file]" << std::endl;
        return (EXIT_FAILURE);
    }
    BitcoinExchange exchange;
    try
    {
        exchange.parse(std::string(argv[1]));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (EXIT_SUCCESS);
}