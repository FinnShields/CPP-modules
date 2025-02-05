/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:01:22 by fshields          #+#    #+#             */
/*   Updated: 2024/10/21 10:50:46 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("Default form"), isSigned(false), gradeToSign(150), gradeToExec(150)
{
    std::cout << "*Form default constructor called*" << std::endl;
}

Form::Form(std::string name, int toSign, int toExec): name(name), isSigned(false), gradeToSign(toSign), gradeToExec(toExec)
{
    std::cout << "*Form constructor called*" << std::endl;
}

Form::Form(const Form& f): name(f.name), isSigned(f.isSigned), gradeToSign(f.gradeToSign), gradeToExec(f.gradeToExec)
{
    std::cout << "*Form copy constructor called*" << std::endl;
}

Form& Form::operator=(const Form& f)
{
    std::cout << "*Form assignment operator called*" << std::endl;
    if (this == &f)
        return (*this);
    isSigned = f.isSigned;
    return (*this);
}

Form::~Form()
{
    std::cout << "*Form destructor called*" << std::endl;
}

const char *Form::GradeTooHighException::what() const noexcept
{
    return "Exception: Grade is too high for this form";
}

const char *Form::GradeTooLowException::what() const noexcept
{
    return "Exception: Grade is too low for this form";
}

std::string Form::getName()
{
    return name;
}

bool Form::getIsSigned()
{
    return isSigned;
}

int Form::getGradeToSign()
{
    return gradeToSign;
}

int Form::getGradeToExec()
{
    return gradeToExec;
}

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form& f)
{
    os << "Form name: " << f.getName() << std::endl
    << "Signed? " << (f.getIsSigned() == true ? "true": "false") << std::endl
    << "Grade required to sign: " << f.getGradeToSign() << std::endl
    << "Grade required to execute: " << f.getGradeToExec() << std::endl;
    return (os);
}