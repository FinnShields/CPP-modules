/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:13:17 by fshields          #+#    #+#             */
/*   Updated: 2024/10/28 10:16:35 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span {
    private:
        unsigned int len;
        std::vector<int> values;
    public:
        Span();
        Span(unsigned int len);
        Span(const Span& s);
        ~Span();
        Span& operator=(const Span& s);
        void addNumber(int num);
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif