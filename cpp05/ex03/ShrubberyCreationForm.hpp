/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:35:18 by fshields          #+#    #+#             */
/*   Updated: 2024/10/21 12:19:28 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm & copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm & copy);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};

#endif