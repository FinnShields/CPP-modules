/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 07:54:05 by fshields          #+#    #+#             */
/*   Updated: 2024/10/28 08:01:41 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <array>

int main()
{
    //using easyfind to find values in a vector
    std::vector<int> vec = {4, 7, 2, 9, 1, 2};
    std::cout << "----Vector-----" << std::endl;
    std::cout << "index of first found '2': " << easyfind(vec, 2) << std::endl;
    std::cout << "index of first found '8': " << easyfind(vec, 8) << std::endl;

    //and now an array
    std::array<int, 5> arr = {3, 4, 7, 0, 1};
    std::cout << "----Array-----" << std::endl;
    std::cout << "index of first found '1': " << easyfind(arr, 1) << std::endl;
    std::cout << "index of first found '6': " << easyfind(arr, 6) << std::endl;
}