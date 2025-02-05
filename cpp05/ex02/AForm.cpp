/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:01:22 by fshields          #+#    #+#             */
/*   Updated: 2024/10/21 12:33:28 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("Default form"), isSigned(false), gradeToSign(150), gradeToExec(150)
{
    std::cout << "*AForm default constructor called*" << std::endl;
}

AForm::AForm(std::string name, std::string target, int toSign, int toExec): name(name), target(target), isSigned(false), gradeToSign(toSign), gradeToExec(toExec)
{
    std::cout << "*AForm constructor called*" << std::endl;
}

AForm::AForm(const AForm& f): name(f.name), isSigned(f.isSigned), gradeToSign(f.gradeToSign), gradeToExec(f.gradeToExec)
{
    std::cout << "*AForm copy constructor called*" << std::endl;
}

AForm& AForm::operator=(const AForm& f)
{
    std::cout << "*AForm assignment operator called*" << std::endl;
    if (this == &f)
        return (*this);
    isSigned = f.isSigned;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "*AForm destructor called*" << std::endl;
}

const char *AForm::GradeTooHighException::what() const noexcept
{
    return "Exception: Grade is too high for this form";
}

const char *AForm::GradeTooLowException::what() const noexcept
{
    return "Exception: Grade is too low for this form";
}

const char *AForm::FormNotSignedException::what() const noexcept
{
    return "Exception: Form hasn't been signed yet";
}

std::string AForm::getName()
{
    return name;
}

std::string AForm::getTarget() const
{
    return target;
}

void AForm::setTarget(std::string target)
{
    this->target = target;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign()
{
    return gradeToSign;
}

int AForm::getGradeToExec() const
{
    return gradeToExec;
}

void AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

bool AForm::ableToExec(Bureaucrat const & b) const
{
    return (b.getGrade() <= getGradeToExec() ? true : false);
}

std::ostream& operator<<(std::ostream& os, AForm& f)
{
    os << "Form name: " << f.getName() << std::endl
    << "Signed? " << (f.getIsSigned() == true ? "true": "false") << std::endl
    << "Grade required to sign: " << f.getGradeToSign() << std::endl
    << "Grade required to execute: " << f.getGradeToExec() << std::endl;
    return (os);
}