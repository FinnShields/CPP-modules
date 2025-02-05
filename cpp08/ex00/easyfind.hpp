/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 07:38:26 by fshields          #+#    #+#             */
/*   Updated: 2024/10/28 08:02:51 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
int easyfind(T container, int val)
{
    auto it = std::find(container.begin(), container.end(), val);
    return (it == container.end()) ? -1 : (it - container.begin());
}

#endif