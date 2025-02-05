/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:10:35 by fshields          #+#    #+#             */
/*   Updated: 2024/10/24 11:39:35 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T array[], size_t len, void (*func)(T&))
{
    for (size_t i = 0; i < len; i ++)
        func(array[i]);
}

template <typename T>
void increment(T &a)
{
    a ++;
}

#endif