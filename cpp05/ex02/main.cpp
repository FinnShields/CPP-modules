/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:20:46 by fshields          #+#    #+#             */
/*   Updated: 2024/10/22 08:27:05 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    ShrubberyCreationForm form1("home");
    Bureaucrat alan("Alan Johnson", 2);
    Bureaucrat mark;
    
    //unsuccessful attempt to sign form1
    try
    {
        mark.signForm(form1);
        form1.execute(alan);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //then successfully
    try
    {
        alan.signForm(form1);
        form1.execute(alan);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    RobotomyRequestForm form2("Sophie Hortensia Chapman");
    
    //successful sign, followed by unsuccessful exec
    try
    {
        alan.signForm(form2);
        form2.execute(mark);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //then successfully
    try
    {
        alan.signForm(form2);
        form2.execute(alan);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    PresidentialPardonForm form3("Father Billy Cake");

    //valid executor, but unsigned form
    try
    {
        form3.execute(alan);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //then successfully
    try
    {
        alan.signForm(form3);
        form3.execute(alan);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}