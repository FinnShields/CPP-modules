/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:20:42 by fshields          #+#    #+#             */
/*   Updated: 2024/10/28 10:16:46 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int len): len(len) {}

Span::Span(const Span& s): len(s.len), values(s.values) {}

Span::~Span() {}

Span& Span::operator=(const Span& s)
{
    this->len = s.len;
    this->values = s.values;
    return *this;
}

void Span::addNumber(int num)
{
    if (values.size() == len)
        throw std::length_error("Object already full");
    values.push_back(num);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (auto it = begin; it != end; it++)
        addNumber(*it);
}

unsigned int Span::longestSpan()
{
    if (values.size() <= 1)
        throw std::logic_error("Object contains insufficient values");
    int max = *(std::max_element(values.begin(), values.end()));
    int min = *(std::min_element(values.begin(), values.end()));
    return max - min;
}

unsigned int Span::shortestSpan()
{
    if (values.size() <= 1)
        throw std::logic_error("Object contains insufficient values");
    std::vector<int> copy = values;
    std::sort(copy.begin(), copy.end());
    unsigned int rtn = copy[1] - copy[0];
    for (unsigned int i = 1; i < copy.size() - 1; i++)
        if ((unsigned int) copy[i + 1] - copy[i] < rtn)
            rtn = copy[i + 1] - copy[i];
    return (rtn);
}