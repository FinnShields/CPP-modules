/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:01:20 by fshields          #+#    #+#             */
/*   Updated: 2024/10/21 10:54:26 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;
    public:
        Form();
        Form(std::string name, int toSign, int toExec);
        Form(const Form& f);
        Form& operator=(const Form& f);
        ~Form();
        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const noexcept override;
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const noexcept override;
        };
        std::string getName();
        bool getIsSigned();
        int getGradeToSign();
        int getGradeToExec();
        void beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, Form& f);

#endif