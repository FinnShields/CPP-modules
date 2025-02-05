/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:07:29 by fshields          #+#    #+#             */
/*   Updated: 2024/11/18 15:48:12 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <deque>
# include <stack>
// # include "MutantStack.tpp"

template<class T>
class MutantStack: public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack<T>& ms);
        MutantStack<T>& operator=(const MutantStack<T>& ms);
        ~MutantStack();
        class iterator {
            using iterator_category = std::random_access_iterator_tag;
            using difference_type = std::ptrdiff_t;
            private:
                T* m_ptr;
            public:
                iterator(T* ptr): m_ptr(ptr) {};
                T& operator*() const { return *m_ptr; };
                T* operator->() { return m_ptr; };
                iterator& operator++() { m_ptr++; return *this; };
                iterator& operator--() { m_ptr--; return *this; };
                iterator operator++(int) { iterator temp = *this; ++(*this); return temp; };
                iterator operator--(int) { iterator temp = *this; --(*this); return temp; };
                bool operator==(const iterator& other) { return m_ptr == &(*other); };
                bool operator!=(const iterator& other) { return m_ptr != &(*other); };
        };
        iterator begin();
        iterator end();
        
};

#endif