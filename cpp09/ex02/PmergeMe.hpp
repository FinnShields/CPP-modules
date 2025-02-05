/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:54:04 by fshields          #+#    #+#             */
/*   Updated: 2024/11/27 10:55:01 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>

typedef struct s_element {
    public:
        int a;
        size_t b;
        int i;
        s_element() {};
        s_element(int a, size_t b, int i): a(a), b(b), i(i) {};
} t_element;

class PmergeMe {
    private:
        PmergeMe(const PmergeMe& rhs);
        PmergeMe& operator=(const PmergeMe& rhs);
        std::vector<t_element *> getPairs(std::vector<size_t> sequence);
        std::deque<t_element *> getPairs(std::deque<size_t> sequence);
        size_t getNextIndexToSort(size_t previous, size_t size);
        void binaryInsert(size_t index, std::vector<t_element *>& pairs, std::vector<size_t>& main);
        void binaryInsert(size_t index, std::deque<t_element *>& pairs, std::deque<size_t>& main);
        bool correctPosition(size_t value, std::vector<size_t>& main, size_t i);
        bool correctPosition(size_t value, std::deque<size_t>& main, size_t i);
        void getNextGroupSize(std::vector<size_t>& groupSizeSequence);
        void getNextGroupSize(std::deque<size_t>& groupSizeSequence);
        void resetStatics (size_t& totalGiven, size_t& leftOfCurrentGroup, size_t& i);
        void clearStructs(std::vector<t_element *>& vec);
        void clearStructs(std::deque<t_element *>& deq);
    public:
        PmergeMe();
        ~PmergeMe();
        std::vector<size_t> fordJohnson(std::vector<size_t> sequence);
        std::deque<size_t> fordJohnson(std::deque<size_t> sequence);
        void validateInput(std::vector<size_t>& vec, int argc, char *argv[]);
        void display(std::vector<size_t>& vec);
    
};

#endif