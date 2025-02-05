/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:38:54 by fshields          #+#    #+#             */
/*   Updated: 2024/11/27 11:04:14 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Error: no argument(s) given!\nUsage: ./PmergeMe [positive integer sequence]\n";
        return (EXIT_FAILURE);
    }
    std::vector<size_t> vec;
    std::vector<size_t> vecSorted;
    std::deque<size_t> deq;
    std::deque<size_t> deqSorted;
    PmergeMe merge;
    try
    {
        merge.validateInput(vec, argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (EXIT_FAILURE);
    }
    
    for (auto it = vec.begin(); it != vec.end(); it++)
        deq.push_back(*it);
    
    auto start = std::chrono::high_resolution_clock::now();
    vecSorted = merge.fordJohnson(vec);
    auto stop = std::chrono::high_resolution_clock::now();
    auto vecTime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    start = std::chrono::high_resolution_clock::now();
    deqSorted = merge.fordJohnson(deq);
    stop = std::chrono::high_resolution_clock::now();
    auto deqTime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    std::cout << "Before: ";
    merge.display(vec);
    std::cout << "After: ";
    merge.display(vecSorted);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime.count() << " μs" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << deqTime.count() << " μs" << std::endl;
    return (EXIT_SUCCESS);
}