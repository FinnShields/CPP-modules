/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:44:25 by fshields          #+#    #+#             */
/*   Updated: 2024/10/22 09:25:17 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "*Intern default constructor called*" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    (void) copy;
    std::cout << "*Intern copy constructor called*" << std::endl;
}

Intern::~Intern()
{
    std::cout << "*Intern destructor called*" << std::endl;
}

Intern& Intern::operator=(const Intern& copy)
{
    (void) copy;
    std::cout << "*Intern assignment operator called*" << std::endl;
    return (*this);
}

const char *Intern::NoSuchFormException::what() const noexcept
{
    return "Exception: This form doesn't exist!";
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm *newForm;
    newForm = (!name.compare("shrubbery creation")) ? (AForm *) new ShrubberyCreationForm(target) :
            (!name.compare("robotomy request")) ? (AForm *) new RobotomyRequestForm(target) :
            (!name.compare("presidential pardon")) ? (AForm *) new PresidentialPardonForm(target) :
            nullptr;
    if (!newForm)
        throw NoSuchFormException();
    return newForm;
}
