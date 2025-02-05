/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:35:20 by fshields          #+#    #+#             */
/*   Updated: 2024/10/22 08:17:01 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", target, 72, 45)
{
    std::cout << "*Robotomy Request Form constructor called*" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "*Robotomy Request Form destructor called*" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy): AForm("Robotomy Request Form", copy.getTarget(), 72, 45)
{
    std::cout << "*Robotomy Request Form copy constructor called*" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    std::cout << "*Robotomy Request Form assignment operator called*" << std::endl;
    if (this == &copy)
        return (*this);
    setTarget(copy.getTarget());
    return (*this); 
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!ableToExec(executor))
        throw GradeTooLowException();
    if (!getIsSigned())
        throw FormNotSignedException();
    std::cout << "***brrbbrrrbbddrrrdrrr***" << std::endl;
    std::srand((size_t) std::time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << getTarget() << " was robotomised successfully!" << std::endl;
    else
        std::cout << getTarget() << "'s robotomy was not successful :(" << std::endl;
}