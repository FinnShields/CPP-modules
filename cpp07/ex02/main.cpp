/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 07:23:27 by fshields          #+#    #+#             */
/*   Updated: 2024/10/25 09:28:12 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"
# include "Array.tpp"

int main()
{
    //declaring Array, adding some values
    Array<int> array1(5);
    std::cout << "Size of array1: " << array1.size() << std::endl;
    array1[0] = 6;
    array1[1] = 4;
    std::cout << "First and second elements: " << array1[0] << " " << array1[1] << std::endl;
    
    //new array with different data type
    Array<std::string> array2(2);
    std::cout << std::endl << "Size of array2: " << array2.size() << std::endl;
    array2[0] = "Good";
    array2[1] = "Afternoon";
    std::cout << "Contents: " << array2[0] << " " << array2[1] << std::endl;

    //Creating empty Array with default constructor
    Array<char> array3;
    std::cout << std::endl << "Size of array3: " << array3.size() << std::endl;
    
    //Using copy constructor
    Array<int> array4(array1);
    std::cout << "Size of array4: " << array4.size() << std::endl;
    std::cout << "First and second elements: " << array4[0] << " " << array4[1] << std::endl;
    
    //Changing contents of array1, to show array4 contains a deep copy of the content
    array1[0] = 0;
    array1[1] = 0;
    std::cout << "First and second elements of array4: " << array4[0] << " " << array4[1] << std::endl;

    //Using assignment operator
    Array<std::string> array5;
    array5 = array2;
    std::cout << "Contents of array5: " << array5[0] << " " << array5[1] << std::endl;

}