/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:20:42 by fshields          #+#    #+#             */
/*   Updated: 2024/10/21 10:50:35 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Mark Corrigan"), grade(150)
{
    std::cout << "*Bureaucrat default constructor called*" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
    std::cout << "*Bureaucrat constructor called*" << std::endl;
    if (this->getGrade() > 150)
        throw GradeTooLowException();
    if (this->getGrade() < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& b): name(b.name), grade(b.grade)
{
    std::cout << "*Bureaucrat copy constructor called*" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
    std::cout << "*Bureaucrat assignment operator called*" << std::endl;
    if (this == &b)
        return *this;
    grade = b.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "*Bureaucrat destructor called*" << std::endl;
}

std::string Bureaucrat::getName()
{
    return (this->name);
}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Exception: Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Exception: Grade too low!";
}

void Bureaucrat::incrementGrade()
{
    if (this->getGrade() >= 2)
        this->grade --;
    else
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    if (this->getGrade() <= 149)
        this->grade ++;
    else
        throw GradeTooLowException();
}

void Bureaucrat::signForm(Form& f)
{
    if (getGrade() <= f.getGradeToSign()) {
        std::cout << getName() << " signed " << f.getName() << std::endl;
    }
    else
        std::cout << getName() << " couldn't sign " << f.getName() << " because their grade is too low" << std::endl;
    f.beSigned(*this);
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}
