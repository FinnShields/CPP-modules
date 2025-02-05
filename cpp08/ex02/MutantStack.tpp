/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:49:37 by fshields          #+#    #+#             */
/*   Updated: 2024/11/18 15:48:19 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP

# include "MutantStack.hpp"

template <class T>
MutantStack<T>::MutantStack() {}

template <class T>
MutantStack<T>::MutantStack(const MutantStack<T>& ms) { *this = ms; }

template <class T>
MutantStack<T>::~MutantStack() {}

template <class T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& ms) { (void)ms; return *this; }

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return iterator(&(*(this->c.begin()))); }

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return iterator(&(*(this->c.end()))); }


#endif