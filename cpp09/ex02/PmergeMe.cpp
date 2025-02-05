/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:46:40 by fshields          #+#    #+#             */
/*   Updated: 2024/11/27 10:56:26 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& rhs) { (void) rhs; }

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) { (void) rhs; return *this; }

void PmergeMe::clearStructs(std::vector<t_element *>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        delete(vec[i]);
}

void PmergeMe::clearStructs(std::deque<t_element *>& deq)
{
    for (size_t i = 0; i < deq.size(); i++)
        delete(deq[i]);
}

void PmergeMe::validateInput(std::vector<size_t>& vec, int argc, char *argv[])
{
    std::string str;
    
    for (size_t i = 1; i < (size_t) argc; i++)
    {
        str = argv[i];
        for (size_t j = 0; j < str.length(); j++)
            if (!std::isdigit(str[j]))
                throw std::invalid_argument("Error: contains a non-digit char, what are you playing at?");
        vec.push_back((size_t) std::atoi(str.c_str()));
    }
    for (size_t i = 0; i < vec.size(); i++)
        for (size_t j = 0; j < i; j++)
            if (vec[i] == vec[j])
                throw std::invalid_argument("Error: there are duplicates, we don't like that at ALL");
    if (vec.size() >= 5000)
        throw std::invalid_argument("Error: there are way too many numbers, let's keep it under 5000 plz!");
}

void PmergeMe::display(std::vector<size_t>& vec)
{
    if (vec.size() <= 5)
    {
        for (auto it = vec.begin(); it != vec.end(); it++)
            std::cout << *it << " ";
    }
    else
    {
        for (size_t i = 0; i < 4; i++)
            std::cout << vec[i] << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

//returns the given sequence in pairs ordered by the larger member. Recursively calls fordJohnson
std::vector<t_element *> PmergeMe::getPairs(std::vector<size_t> sequence)
{
    std::vector<t_element *> temp;
    std::vector<size_t> a_ordered;
    std::vector<t_element *> rtn;
    int a;
    int b;
    
    for (size_t j = 0; j < sequence.size(); j++)
    {
        if (j % 2 == 0)
        {
            a = sequence[j];
            if (j == sequence.size() - 1)
            {
                b = a;
                a = -1;
                temp.push_back(new t_element(a, b, -1));
            }
        }
        if (j % 2 == 1)
        {
            b = sequence[j];
            if (b > a)
                std::swap(a, b);
            temp.push_back(new t_element(a, b, -1));
        }
    }
    for (size_t j = 0; j < temp.size(); j++)
        if (temp[j]->a != -1)
            a_ordered.push_back((size_t) temp[j]->a);
    a_ordered = fordJohnson(a_ordered);
    for (size_t j = 0; j < a_ordered.size(); j++)
        for (size_t k = 0; k < temp.size(); k++)
            if ((size_t) temp[k]->a ==  a_ordered[j])
                rtn.push_back(new t_element(temp[k]->a, temp[k]->b, j + 1));
    for (size_t k = 0; k < temp.size(); k++)
            if (temp[k]->a ==  -1)
                rtn.push_back(new t_element(temp[k]->a, temp[k]->b, rtn.size() + 1));
    clearStructs(temp);
    return rtn;
}

std::deque<t_element *> PmergeMe::getPairs(std::deque<size_t> sequence)
{
    std::deque<t_element *> temp;
    std::deque<size_t> a_ordered;
    std::deque<t_element *> rtn;
    int a;
    int b;
    
    for (size_t j = 0; j < sequence.size(); j++)
    {
        if (j % 2 == 0)
        {
            a = sequence[j];
            if (j == sequence.size() - 1)
            {
                b = a;
                a = -1;
                temp.push_back(new t_element(a, b, -1));
            }
        }
        if (j % 2 == 1)
        {
            b = sequence[j];
            if (b > a)
                std::swap(a, b);
            temp.push_back(new t_element(a, b, -1));
        }
    }
    for (size_t j = 0; j < temp.size(); j++)
        if (temp[j]->a != -1)
            a_ordered.push_back((size_t) temp[j]->a);
    a_ordered = fordJohnson(a_ordered);
    for (size_t j = 0; j < a_ordered.size(); j++)
        for (size_t k = 0; k < temp.size(); k++)
            if ((size_t) temp[k]->a ==  a_ordered[j])
                rtn.push_back(new t_element(temp[k]->a, temp[k]->b, j + 1));
    for (size_t k = 0; k < temp.size(); k++)
            if (temp[k]->a ==  -1)
                rtn.push_back(new t_element(temp[k]->a, temp[k]->b, rtn.size() + 1));
    clearStructs(temp);
    return rtn;
}

//if true, value should be inserted after current
bool PmergeMe::correctPosition(size_t value, std::vector<size_t>& main, size_t i)
{
    size_t current = main[i];
    size_t next = (i < main.size() - 1) ? main[i + 1] : __LONG_MAX__;
    if ((value > current && value < next) || value == current)
        return true;
    return false;
}

bool PmergeMe::correctPosition(size_t value, std::deque<size_t>& main, size_t i)
{
    size_t current = main[i];
    size_t next = (i < main.size() - 1) ? main[i + 1] : __LONG_MAX__;
    if ((value > current && value < next) || value == current)
        return true;
    return false;
}

//adds pend[index] to main sequence
void PmergeMe::binaryInsert(size_t index, std::vector<t_element *>& pairs, std::vector<size_t>& main)
{
    if (index == 1)
    {
        auto it = main.begin();
        main.insert(it, pairs[0]->b);
        delete(*pairs.begin());
        pairs.erase(pairs.begin());
        return ;
    }
    t_element *element;
    for (size_t j = 0; j < pairs.size(); j ++)
        if ((size_t) pairs[j]->i == index)
            element = pairs[j];
    size_t offset = 0;
    for (size_t j = 0; j < main.size(); j++)
        if (main[j] == (size_t) element->a)
            offset = main.size() - j;
    size_t searchArea = main.size() - offset;
    int searchIndex = searchArea / 2;
    searchArea /= 2; 
    while (!correctPosition(element->b, main, searchIndex))
    {
        if (searchArea != 1)
            searchArea /= 2;
        if (main[searchIndex] > element->b)
            searchIndex -= searchArea;
        else if (main[searchIndex] < element->b)
            searchIndex += searchArea;
        if (element->b < main[0])
        {
            searchIndex = -1;
            break;
        }
        if (element->b > main[main.size() - 1])
        {
            searchIndex = main.size() - 1;
            break;
        }
    }
    auto it = main.begin();
    if (searchIndex == (int) main.size()) {
        main.emplace_back(element->b);
        for (size_t j = 0; j < main.size(); j++)
                std::cout << main[j] << " ";
        std::cout << std::endl;
    }
    else
        main.insert(it + searchIndex + 1, element->b);
    for (size_t j = 0; j < pairs.size(); j++) {
        if ((size_t) pairs[j]->i == index) {
            delete (*(pairs.begin() + j));
            pairs.erase(pairs.begin() + j);
        }
    }
}

void PmergeMe::binaryInsert(size_t index, std::deque<t_element *>& pairs, std::deque<size_t>& main)
{
    if (index == 1)
    {
        auto it = main.begin();
        main.insert(it, pairs[0]->b);
        delete(*pairs.begin());
        pairs.erase(pairs.begin());
        return ;
    }
    t_element *element;
    for (size_t j = 0; j < pairs.size(); j ++)
        if ((size_t) pairs[j]->i == index)
            element = pairs[j];
    size_t offset = 0;
    for (size_t j = 0; j < main.size(); j++)
        if (main[j] == (size_t) element->a)
            offset = main.size() - j;
    size_t searchArea = main.size() - offset;
    int searchIndex = searchArea / 2;
    searchArea /= 2; 
    while (!correctPosition(element->b, main, searchIndex))
    {
        if (searchArea != 1)
            searchArea /= 2;
        if (main[searchIndex] > element->b)
            searchIndex -= searchArea;
        else if (main[searchIndex] < element->b)
            searchIndex += searchArea;
        if (element->b < main[0])
        {
            searchIndex = -1;
            break;
        }
        if (element->b > main[main.size() - 1])
        {
            searchIndex = main.size() - 1;
            break;
        }
    }
    auto it = main.begin();
    if (searchIndex == (int) main.size()) {
        main.emplace_back(element->b);
        for (size_t j = 0; j < main.size(); j++)
                std::cout << main[j] << " ";
        std::cout << std::endl;
    }
    else
        main.insert(it + searchIndex + 1, element->b);
    for (size_t j = 0; j < pairs.size(); j++) {
        if ((size_t) pairs[j]->i == index) {
            delete (*(pairs.begin() + j));
            pairs.erase(pairs.begin() + j);
        }
    }
}

//finds the next group size for efficient binary insertion, sequence is 2, 2, 6, 10, 22 etc
void PmergeMe::getNextGroupSize(std::vector<size_t>& groupSizeSequence)
{
    size_t last = groupSizeSequence.back();
    size_t secondLast = groupSizeSequence[groupSizeSequence.size() - 2];
    groupSizeSequence.push_back(((last + secondLast) * 2) - last);
}

void PmergeMe::getNextGroupSize(std::deque<size_t>& groupSizeSequence)
{
    size_t last = groupSizeSequence.back();
    size_t secondLast = groupSizeSequence[groupSizeSequence.size() - 2];
    groupSizeSequence.push_back(((last + secondLast) * 2) - last);
}

void PmergeMe::resetStatics(size_t& totalGiven, size_t& leftOfCurrentGroup, size_t& i)
{
    totalGiven = 0;
    i = 0;
    leftOfCurrentGroup = 1;
}

//finds the next pend index to add by binary insertion according the group sizes and position within each group
size_t PmergeMe::getNextIndexToSort(size_t previous, size_t size)
{
    static std::vector<size_t> groupSizeSequence = {2, 2, 6, 10, 22, 42};
    static size_t leftOfCurrentGroup = 1;
    static size_t i = 0;
    static size_t totalGiven = 0;
    
    if (previous == 0) {
        totalGiven ++;
        if (totalGiven == size)
            resetStatics(totalGiven, leftOfCurrentGroup, i);
        return 1;
    }
    if (previous == 1) {
        totalGiven ++;
        if (totalGiven == size)
            resetStatics(totalGiven, leftOfCurrentGroup, i);
        return (size == 2) ? 2 : 3;
    }
    size_t totalSize = 0;
    for (auto it = groupSizeSequence.begin(); it != groupSizeSequence.end(); it++)
        totalSize += *it;
    if (totalSize > size)
        getNextGroupSize(groupSizeSequence);
    while (leftOfCurrentGroup--) {
        totalGiven ++;
        if (totalGiven == size)
            resetStatics(totalGiven, leftOfCurrentGroup, i);
        return previous - 1;
    }
    i ++;
    leftOfCurrentGroup = groupSizeSequence[i] - 1;
    size_t rtn = previous + (groupSizeSequence[i - 1] - 1) + groupSizeSequence[i];
    while (rtn > size) {
        rtn--;
        leftOfCurrentGroup--;
    }
    totalGiven ++;
    if (totalGiven == size)
        resetStatics(totalGiven, leftOfCurrentGroup, i);;
    return rtn;
}

//splits values into pairs, recursively sorts them by larger value, and inserts the remaining values in an efficient order
std::vector<size_t> PmergeMe::fordJohnson(std::vector<size_t> sequence)
{
    if (sequence.size() == 1)
        return sequence;
    std::vector<t_element *> pairs;
    std::vector<size_t> main;
    size_t insertIndex = 0;
    size_t pendSize;
    pairs = getPairs(sequence);
    for (size_t j = 0; j < pairs.size(); j++)
        if (pairs[j]->a != -1)
            main.push_back((size_t) pairs[j]->a);
    pendSize = pairs.size();
    while (pairs.size() > 0)
    {
        insertIndex = getNextIndexToSort(insertIndex, pendSize);
        binaryInsert(insertIndex, pairs, main);
    }
    clearStructs(pairs);
    return main;
}

std::deque<size_t> PmergeMe::fordJohnson(std::deque<size_t> sequence)
{
    if (sequence.size() == 1)
        return sequence;
    std::deque<t_element *> pairs;
    std::deque<size_t> main;
    size_t insertIndex = 0;
    size_t pendSize;
    pairs = getPairs(sequence);
    for (size_t j = 0; j < pairs.size(); j++)
        if (pairs[j]->a != -1)
            main.push_back((size_t) pairs[j]->a);
    pendSize = pairs.size();
    while (pairs.size() > 0)
    {
        insertIndex = getNextIndexToSort(insertIndex, pendSize);
        binaryInsert(insertIndex, pairs, main);
    }
    clearStructs(pairs);
    return main;
}