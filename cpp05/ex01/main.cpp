/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:20:46 by fshields          #+#    #+#             */
/*   Updated: 2024/10/21 10:42:15 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat mark;
    mark.incrementGrade();
    Form newForm("New Form", 149, 20);
    std::cout << newForm << std::endl;
    try
    {
        mark.signForm(newForm);
        std::cout << newForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    Form superiorForm("Superior Form", 2, 1);
    std::cout << superiorForm << std::endl;
    try
    {
        mark.signForm(superiorForm);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    Bureaucrat jeff("Jeff", 1);
    try
    {
        jeff.signForm(superiorForm);
        std::cout << superiorForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}