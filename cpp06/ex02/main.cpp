/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:23:18 by fshields          #+#    #+#             */
/*   Updated: 2024/10/24 10:33:39 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <ctime>

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base *generate(void)
{
    std::srand(std::time(NULL));
    switch (std::rand() % 3) {
        case (0):
            return new A();
        case (1):
            return new B();
        case (2):
            return new C();
        default:
            return nullptr;
    }
    
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != nullptr)
        std::cout << "Type identified as: A" << std::endl;
    else if (dynamic_cast<B *>(p) != nullptr)
        std::cout << "Type identified as: B" << std::endl;
    else if (dynamic_cast<C *>(p) != nullptr)
        std::cout << "Type identified as: C" << std::endl;
    else
        std::cerr << "Hmm, it's not A, B or C..." << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void) dynamic_cast<A&>(p);
        std::cout << "Type identified as: A" << std::endl;
        return ;
    }
    catch(const std::exception& e){}
    try
    {
        (void) dynamic_cast<B&>(p);
        std::cout << "Type identified as: B" << std::endl;
        return ;
    }
    catch(const std::exception& e){}
    try
    {
        (void) dynamic_cast<C&>(p);
        std::cout << "Type identified as: C" << std::endl;
        return ;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    Base *ptr = generate();
    std::cout << "Using pointer function: " << std::endl;
    identify(ptr);
    std::cout << std::endl << "Using reference function: " << std::endl;
    identify(*ptr);
}