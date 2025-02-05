/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 07:28:50 by fshields          #+#    #+#             */
/*   Updated: 2024/10/25 11:56:34 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <class T>
Array<T>::Array(): n(0), content(nullptr) {}

template <class T>
Array<T>::Array(unsigned int n): n(n), content(new T[n]) {}

template <class T>
Array<T>::Array(const Array<T>& a): n(a.size()), content(new T[a.size()])
{
    for (unsigned int i = 0; i < n; i ++)
    {
        this->content[i] = a[i];
    }
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& a)
{
    n = a.size();
    delete [] content;
    content = new T[n];
    for (unsigned int i = 0; i < n; i ++)
        (*this)[i] = a[i];
    return *this;
}

template <class T>
Array<T>::~Array()
{
    delete[] content;
}

template <class T>
T& Array<T>::operator[](unsigned int i) const
{
    if (i >= n)
        throw std::out_of_range("out of bounds");
    return content[i];
}

template <class T>
unsigned int Array<T>::size() const
{
    return n;
}

#endif
