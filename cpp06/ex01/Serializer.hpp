/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:36:49 by fshields          #+#    #+#             */
/*   Updated: 2024/10/24 08:44:36 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <iostream>

typedef struct s_data {
    std::string favouriteTea;
    std::string favouriteCoffee;
} Data;

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& s);
        ~Serializer();
        Serializer& operator=(const Serializer& s);
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif