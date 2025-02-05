/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:20:49 by fshields          #+#    #+#             */
/*   Updated: 2024/10/21 09:57:17 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "iostream"
# include "Form.hpp"
# include <exception>

class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat& operator=(const Bureaucrat& b);
        ~Bureaucrat();
        std::string getName();
        int getGrade();
        void incrementGrade();
        void decrementGrade();
        void signForm(Form& f);
        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const noexcept override;
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const noexcept override;
        };
        
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);

#endif