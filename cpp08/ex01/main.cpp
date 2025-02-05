/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:58:48 by fshields          #+#    #+#             */
/*   Updated: 2024/10/28 09:25:28 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    //tests from subject
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    //my own tests
    Span mySpan = Span(20000);
    try
    {
        //making a large Span with thousands of numbers
        for (int i = 0; i < 1000; i++)
            mySpan.addNumber(7 * i);
        
        //adding more using addRange()
        std::vector<int> vec;
        for (int i = 0; i < 2000; i ++)
            vec.push_back(13 * i);
        mySpan.addRange(vec.begin(), vec.end());

        //then testing out the span funcs
        std::cout << mySpan.shortestSpan() << std::endl;
        std::cout << mySpan.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        //now testing out the error handling
        //first adding a number to a full Span object
        Span newSpan(3);
        newSpan.addNumber(1);
        newSpan.addNumber(2);
        newSpan.addNumber(3);
        newSpan.addNumber(4);
        
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        //then trying to find the span of an empty object
        Span yetMoreSpan(3);
        yetMoreSpan.longestSpan();        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}