/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:36:53 by fshields          #+#    #+#             */
/*   Updated: 2024/10/24 09:11:41 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    //establishing a Data struct
    Data *someData = new Data;
    someData->favouriteTea = "Imperial Green";
    someData->favouriteCoffee = "Presidentti Ruby";
    
    //printing to cout, to show content of data
    std::cout << std::endl << "Content of someData:" << std::endl
    << "favouriteTea: " << someData->favouriteTea << std::endl
    << "favouriteCoffee: " << someData->favouriteCoffee << std::endl;

    //printing memory address of the Data struct
    std::cout << "Address of someData: " << someData << std::endl;

    //serializing the addr and saving it in another ptr
    intptr_t ptr = Serializer::serialize(someData);
    std::cout << std::endl << "Content of ptr, after serialization: " << ptr << std::endl;

    //finally, deserializing into a new pointer and 
    //printing contents of Data again to show it is the same struct
    Data *newPtr = Serializer::deserialize(ptr);
    std::cout << std::endl << "newPtr is pointing to the same Data struct, contents:" << std::endl
    << "favouriteTea: " << newPtr->favouriteTea << std::endl
    << "favouriteCoffee: " << newPtr->favouriteCoffee << std::endl
    << "Address held by newPtr: " << newPtr << std::endl;
    
    delete someData;
}