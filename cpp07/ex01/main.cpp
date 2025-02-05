/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:18:57 by fshields          #+#    #+#             */
/*   Updated: 2024/10/24 11:43:24 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void square(int &n)
{
    n *= n;
}

void turnIntoHive(std::string &s)
{
    s.clear();
    s = "hive";
}

int main ()
{
    //first, an array of ints
    int array1[5] = {1, 2, 3, 4, 5};
    std::cout << "array1 before iteration: " << std::endl;
    for (size_t i = 0; i < 5; i ++)
        std::cout << array1[i] << " ";
    std::cout << std::endl;
    ::iter(array1, 5, &square);
    std::cout << "array1 after iteration: " << std::endl;
    for (size_t i = 0; i < 5; i ++)
        std::cout << array1[i] << " ";
    std::cout << std::endl << std::endl;

    //then, an array of strings
    std::string array2[3] = {"How", "are", "you?"};
    std::cout << "array2 before iteration: " << std::endl;
    for (size_t i = 0; i < 3; i ++)
        std::cout << array2[i] << " ";
    std::cout << std::endl;
    ::iter(array2, 3, &turnIntoHive);
    std::cout << "array2 after iteration: " << std::endl;
    for (size_t i = 0; i < 3; i ++)
        std::cout << array2[i] << " ";
    std::cout << std::endl << std::endl;

    //now iterating with an instantiated template func
    int array3[4] = {5, 6, 7, 8};
    std::cout << "array3 before iteration: " << std::endl;
    for (size_t i = 0; i < 4; i ++)
        std::cout << array3[i] << " ";
    std::cout << std::endl;
    ::iter(array3, 4, &::increment);
    std::cout << "array3 after iteration: " << std::endl;
    for (size_t i = 0; i < 4; i ++)
        std::cout << array3[i] << " ";
    std::cout << std::endl << std::endl;

}