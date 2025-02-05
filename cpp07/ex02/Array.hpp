/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 07:22:25 by fshields          #+#    #+#             */
/*   Updated: 2024/10/25 11:42:26 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T>
class Array {
    private:
        unsigned int n;
        T *content;
        
    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& a);
        Array<T>& operator=(const Array<T>& a);
        ~Array();
        T& operator[](unsigned int i) const;
        unsigned int size() const;
    
};

#endif