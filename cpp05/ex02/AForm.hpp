/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:01:20 by fshields          #+#    #+#             */
/*   Updated: 2024/10/21 12:38:45 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        std::string target;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;
    public:
        AForm();
        AForm(std::string name, std::string target, int toSign, int toExec);
        AForm(const AForm& f);
        AForm& operator=(const AForm& f);
        ~AForm();
        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const noexcept override;
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const noexcept override;
        };
        class FormNotSignedException: public std::exception {
            public:
                virtual const char* what() const noexcept override;
        };
        std::string getName();
        std::string getTarget() const;
        void setTarget(std::string target);
        bool getIsSigned() const;
        int getGradeToSign();
        int getGradeToExec() const;
        void beSigned(Bureaucrat& b);
        bool ableToExec(Bureaucrat const & b) const;
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm& f);

#endif