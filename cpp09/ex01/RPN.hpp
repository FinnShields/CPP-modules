/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:37:28 by fshields          #+#    #+#             */
/*   Updated: 2024/11/27 10:38:48 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>

class RPN {
    private:
        std::stack<int> stack;
        std::string input;
        RPN();
        RPN(const RPN& rhs);
        RPN& operator=(const RPN& rhs);
        bool validInput();
        bool validChar(char c);
        void handleAddition();
        void handleSubtraction();
        void handleMultiplication();
        void handleDivision();
        bool overflowCheck(int a, int b, char operation);
    public:
        RPN(const std::string& input);
        ~RPN();
        void calculate();
    
};

#endif