/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:51:06 by fshields          #+#    #+#             */
/*   Updated: 2024/10/23 12:44:50 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# define INVALID -1
# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

# include <iostream>
# include <limits.h>
# include <cfloat>
# include <iomanip>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& sc);
        ScalarConverter& operator=(const ScalarConverter& sc);
        ~ScalarConverter();
        static int detect(std::string input);
        static void handleChar(char c);
        static void handleInt(int i);
        static void handleFloat(std::string input);
        static void handleDouble(std::string input);
        static bool isInt(std::string input);
        static bool isFloat(std::string input);
        static bool isDouble(std::string input);
    public:
        static void convert(std::string input);
};

#endif