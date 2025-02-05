/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:36:38 by fshields          #+#    #+#             */
/*   Updated: 2024/11/18 16:05:24 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>
#include <stack>

int main()
{
    //tests from the subject:
    
    //with MutantStack
    std::cout << "Mutant stack:\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    //with list
    std::cout << "List:\n";
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    std::list<int>::iterator itl = mlist.begin();
    std::list<int>::iterator itel = mlist.end();
    ++itl;
    --itl;
    while (itl != itel)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }

    //my own tests:
    
    std::cout << "Now testing it with a MutantStack of chars..\n";
    MutantStack<char> cstack;
    cstack.push('H');
    cstack.push('e');
    cstack.push('l');
    cstack.push('l');
    cstack.push('o');
    cstack.push(' ');
    cstack.push('t');
    cstack.push('h');
    cstack.push('e');
    cstack.push('r');
    cstack.push('e');
    cstack.push('!');
    for (auto iterator = cstack.begin(); iterator != cstack.end(); iterator++)
        std::cout << *iterator;
    std::cout << std::endl;
    return 0;
}