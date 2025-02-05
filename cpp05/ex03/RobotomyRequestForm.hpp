/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:35:22 by fshields          #+#    #+#             */
/*   Updated: 2024/10/22 08:16:24 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <ctime>

class RobotomyRequestForm: public AForm
{
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm & copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm & copy);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};

#endif