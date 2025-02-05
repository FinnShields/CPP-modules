/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:35:24 by fshields          #+#    #+#             */
/*   Updated: 2024/10/22 08:21:45 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", target, 25, 5)
{
    std::cout << "*Presidential Pardon Form constructor called*" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "*Presidential Pardon Form destructor called*" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy): AForm("Presidential Pardon Form", copy.getTarget(), 25, 5)
{
    std::cout << "*Presidential Pardon Form copy constructor called*" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    std::cout << "*Presidential Pardon Form assignment operator called*" << std::endl;
    if (this == &copy)
        return (*this);
    setTarget(copy.getTarget());
    return (*this); 
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!ableToExec(executor))
        throw GradeTooLowException();
    if (!getIsSigned())
        throw FormNotSignedException();
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox, all glory be to him" << std::endl;
}