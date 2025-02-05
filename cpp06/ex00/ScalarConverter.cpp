/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:51:09 by fshields          #+#    #+#             */
/*   Updated: 2024/10/24 07:58:46 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& sc)
{
    (void) sc;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& sc)
{
    (void) sc;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isInt(std::string input)
{
    for (size_t i = 0; i < input.size(); i ++)
    {
        if (i == 0 && (input[i] != '-' && !(input[i] <= '9' && input[i] >= '0')))
            return false;
        if (i > 0 && !(input[i] <= '9' && input[i] >= '0'))
            return false;
    }
    return (input.size() == 1 && input[0] == '-') ? false : true;
}

bool ScalarConverter::isFloat(std::string input)
{
    if (!input.compare("+inff") || !input.compare("-inff") || !input.compare("nanf"))
        return true;
    if (input[input.size() - 1] != 'f')
        return false;
    size_t dotCount = 0;
    for (size_t i = 0; i < input.size() - 1; i ++)
    {
        if (i == 0 && (input[i] != '-' && !(input[i] <= '9' && input[i] >= '0')))
            return false;
        if (i > 0 && !(input[i] <= '9' && input[i] >= '0') && input[i] != '.')
            return false;
        if (input[i] == '.')
            dotCount ++;
    }
    return (dotCount == 1 && (input[input.size() - 2] != '.')) ? true : false;
}

bool ScalarConverter::isDouble(std::string input)
{
    if (!input.compare("+inf") || !input.compare("-inf") || !input.compare("nan"))
        return true;
    size_t dotCount = 0;
    for (size_t i = 0; i < input.size(); i ++)
    {
        if (i == 0 && (input[i] != '-' && !(input[i] <= '9' && input[i] >= '0')))
            return false;
        if (i > 0 && !(input[i] <= '9' && input[i] >= '0') && input[i] != '.')
            return false;
        if (input[i] == '.')
            dotCount ++;
    }
    return ((dotCount == 1) && (input[input.size() - 1] != '.')) ? true : false;
}

int ScalarConverter::detect(std::string input)
{
    if (input.size() == 0)
        throw std::invalid_argument("empty string");
    if (isInt(input))
        return INT;
    if (input.size() == 1 && std::isprint(input[0]))
        return CHAR;
    if (isFloat(input))
        return FLOAT;
    if (isDouble(input))
        return DOUBLE;
    return INVALID;
}

void ScalarConverter::handleChar(char c)
{
    std::cout << "char: \'" << c << "\'" << std::endl
    << "int: " << static_cast<int> (c) << std::endl
    << "float: " << static_cast<float> (c) << ".0f" << std::endl
    << "double: " << static_cast<double> (c) << ".0" << std::endl;
}

void ScalarConverter::handleInt(int i)
{
    std::cout << "char: ";
    if (i >= 32 && i <= 127)
        std::cout << "\'" << static_cast<char> (i) << "\'" << std::endl;
    else
        std::cout << "nah, not happening.." << std::endl;
    std::cout << "int: " << i << std::endl
    << "float: " << std::setprecision(1) << std::fixed << static_cast<float> (i) << "f" << std::endl
    << "double: " << static_cast<double> (i) << std::endl;
}

void ScalarConverter::handleFloat(std::string input)
{
    if (!input.compare("+inff") || !input.compare("-inff") || !input.compare("nanf"))
    {
        std::cout << "char: you gotta be kidding me.." << std::endl
        << "int: cmon, no way" << std::endl
        << "float: " << input << std::endl
        << "double: " << input.substr(0, input.size() - 1) << std::endl;
        return ;
    }
    float f = std::stof(input);
    int i = static_cast<int> (f);
    if (static_cast<long> (i) != static_cast<long> (f))
        throw std::out_of_range("int overflow");
    double d = static_cast<double> (f);
    std::cout << "char: ";
    if (f - static_cast<float> (i) == 0.0f && (i >= 32 && i <= 127))
        std::cout << "\'" << (char) i << "\'" << std::endl;
    else
        std::cout << "not today dude" << std::endl;
    std::cout << "int: " << i << std::endl << "float: " 
    << std::setprecision(1) << std::fixed << f
    << "f" << std::endl << "double: " << d << std::endl;
}

void ScalarConverter::handleDouble(std::string input)
{
    if (!input.compare("+inf") || !input.compare("-inf") || !input.compare("nan"))
    {
        std::cout << "char: you gotta be kidding me.." << std::endl
        << "int: cmon, no way" << std::endl
        << "float: " << input + "f" << std::endl
        << "double: " << input << std::endl;
        return ;
    }
    double d = std::stod(input);
    int i = static_cast<int> (d);
    float f = static_cast<float> (d);
    if (static_cast<long> (i) != static_cast<long> (d))
        throw std::out_of_range("int overflow");
    if (static_cast<long> (f) != static_cast<long> (d))
        throw std::out_of_range("float overflow");
    std::cout << "char: ";
    
    if (d - static_cast<double> (i) == 0.0 && (i >= 32 && i <= 127))
        std::cout << "\'" << (char) i << "\'" << std::endl;
    else
        std::cout << "not. gonna. happen." << std::endl;
    std::cout << "int: " << i << std::endl << "float: " << f;
    if (d - static_cast<double> (i) == 0.0)
        std::cout << ".0";
    std::cout << "f" << std::endl << "double: " << d;
    if (d - static_cast<double> (i) == 0.0)
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(std::string input)
{
    switch (detect(input)) {
        case (CHAR):
            handleChar(input[0]);
            break;
        case (INT):
            handleInt(std::stoi(input));
            break;
        case (FLOAT):
            handleFloat(input);
            break;
        case (DOUBLE):
            handleDouble(input);
            break;
        default:
            std::cerr << "Invalid input!" << std::endl;
    }
}