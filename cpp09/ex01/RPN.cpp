/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:43:16 by fshields          #+#    #+#             */
/*   Updated: 2024/11/27 10:45:08 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string& input): input(input)
{
    if (!validInput())
        throw std::invalid_argument("Invalid input\nExample usage: \"3 4 +\"");
}

RPN::RPN(const RPN& rhs): stack(rhs.stack), input(rhs.input) {}

RPN& RPN::operator=(const RPN& rhs) { stack = rhs.stack; input = rhs.input; return *this; }

RPN::~RPN() {}

bool RPN::validChar(char c)
{
    if (std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

bool RPN::validInput()
{
    for (size_t i = 0; i != input.size(); i++)
    {
        if (i % 2 == 0 && !validChar(input[i]))
            return false;
        if (i % 2 == 1 && input[i] != ' ')
            return false;
    }
    return true;
}

void RPN::handleAddition()
{
    if (stack.size() < 2)
        throw std::logic_error("Invalid expression");
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    stack.push(a + b);
    if (overflowCheck(a, b, '+'))
        throw ((long) a + (long) b > 0) ? (std::runtime_error) std::overflow_error("Int overflow") : std::underflow_error("Int underflow");
}

void RPN::handleSubtraction()
{
    if (stack.size() < 2)
        throw std::logic_error("Invalid expression");
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    stack.push(b - a);
    if (overflowCheck(a, b, '-'))
        throw ((long) b - (long) a > 0) ? (std::runtime_error) std::overflow_error("Int overflow") : std::underflow_error("Int underflow");
}

void RPN::handleMultiplication()
{
    if (stack.size() < 2)
        throw std::logic_error("Invalid expression");
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    stack.push(a * b);
    if (overflowCheck(a, b, '*'))
        throw ((long) a * (long) b > 0) ? (std::runtime_error) std::overflow_error("Int overflow") : std::underflow_error("Int underflow");
}

void RPN::handleDivision()
{
    if (stack.size() < 2)
        throw std::logic_error("Invalid expression");
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    stack.push(b / a);
    if (overflowCheck(a, b, '/'))
        throw ((long) b / (long) a > 0) ? (std::runtime_error) std::overflow_error("Int overflow") : std::underflow_error("Int underflow");
}

bool RPN::overflowCheck(int a, int b, char operation)
{
    long result;
    switch (operation) {
        case ('+'):
            result = (long) a + (long) b;
            if ((long) (a + b) != result)
                return true;
            break;
        case ('-'):
            result = (long) b - (long) a;
            if ((long) (b - a) != result)
                return true;
            break;
        case ('*'):
            result = (long) a * (long) b;
            if ((long) (a * b) != result)
                return true;
            break;
        case ('/'):
            result = (long) b / (long) a;
            if ((long) (b / a) != result)
                return true;
            break;
        default:
            throw std::runtime_error("Internal error");
    }
    return false;
}

void RPN::calculate()
{
    for (size_t i = 0; i < input.size(); i += 2)
    {
        (input[i] == '+') ? handleAddition() :
        (input[i] == '-') ? handleSubtraction() :
        (input[i] == '*') ? handleMultiplication() :
        (input[i] == '/') ? handleDivision() :
        stack.push(std::atoi(&input[i]));
    }
    if (stack.size() != 1)
        throw std::logic_error("Invalid expression");
    std::cout << stack.top() << std::endl;
}

