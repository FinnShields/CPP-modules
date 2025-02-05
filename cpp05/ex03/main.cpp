/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:20:46 by fshields          #+#    #+#             */
/*   Updated: 2024/10/22 09:36:14 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *form;
    
    //attempting to make a form with a typo
    try
    {
        form = someRandomIntern.makeForm("rbotomy request", "Bender");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //and correctly
    try
    {
        form = someRandomIntern.makeForm("presidential pardon", "Father Todd Unctious");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //signing and executing the form to show that it works correctly
    Bureaucrat mrsDoyle("Mrs Doyle", 1);
    try
    {
        mrsDoyle.signForm(*form);
        form->execute(mrsDoyle);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete form;
}