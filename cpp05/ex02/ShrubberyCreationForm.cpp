/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:35:15 by fshields          #+#    #+#             */
/*   Updated: 2024/10/21 12:49:50 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", target, 145, 137)
{
    std::cout << "*Shrubbery Creation Form constructor called*" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "*Shrubbery Creation Form destructor called*" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy): AForm("Shrubbery Creation Form", copy.getTarget(), 145, 137)
{
    std::cout << "*Shrubbery Creation Form copy constructor called*" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    std::cout << "*Shrubbery Creation Form assignment operator called*" << std::endl;
    if (this == &copy)
        return (*this);
    setTarget(copy.getTarget());
    return (*this); 
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!ableToExec(executor))
        throw GradeTooLowException();
    if (!getIsSigned())
        throw FormNotSignedException();
    std::ofstream newFile(getTarget() + "_shrubbery");
    newFile << "        /\\\n"
    << "       /  \\\n"
    << "      /    \\\n"
    << "     / |/   \\\n"
    << "    /        \\\n"
    << "   /      \\|  \\\n"
    << "  /   |/       \\\n"
    << " /           \\| \\\n"
    << "/________________\\\n"
    << "      |    |      \n"
    << "      |    |      \n";
   newFile.close();
}