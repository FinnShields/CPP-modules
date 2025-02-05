/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:20:46 by fshields          #+#    #+#             */
/*   Updated: 2024/10/21 08:56:50 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    //Using default constructor, catching exception when grade is decremented too low
    Bureaucrat mark;
    try
    {
        std::cout << mark << std::endl;
        mark.incrementGrade();
        std::cout << mark << std::endl;
        mark.decrementGrade();
        mark.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    //Using other constructor, catching exception when grade goes too high"
    Bureaucrat jeremy("Jeremy Usbourne", 1);
    try
    {
        std::cout << jeremy << std::endl;
        jeremy.incrementGrade();
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    //Trying to create a bureaucrat with too high a grade
    try
    {
        Bureaucrat alan("Alan Johnson", -1000);
        std::cout << alan << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}