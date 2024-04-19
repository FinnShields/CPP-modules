/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:08:58 by fshields          #+#    #+#             */
/*   Updated: 2024/04/05 13:52:02 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <string>
# include <iostream>

class PhoneBook {
	private:
		Contact contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void add_contact( Contact newContact );
		void display_all();
		void search( std::string index );
};

#endif