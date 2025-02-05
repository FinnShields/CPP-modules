/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:37:00 by fshields          #+#    #+#             */
/*   Updated: 2024/10/22 08:44:08 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& copy);
        ~Intern();
        Intern& operator=(const Intern& copy);
        AForm *makeForm(std::string name, std::string target);
        class NoSuchFormException: public std::exception {
            public:
                virtual const char* what() const noexcept override;
        };
};

#endif