/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:36:51 by fshields          #+#    #+#             */
/*   Updated: 2024/10/24 08:52:28 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& s)
{
    (void) s;
}

Serializer::~Serializer() {}

Serializer& Serializer::operator=( const Serializer& s)
{
    (void) s;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t> (ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *> (raw);
}