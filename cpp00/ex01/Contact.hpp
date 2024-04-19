/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 08:50:28 by fshields          #+#    #+#             */
/*   Updated: 2024/04/05 13:51:24 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include <iomanip>

class Contact {
	private:
		int	index;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string number;
		std::string dark_secret;
	public:
		Contact();
		Contact( int i );
		~Contact();
		void display();
		void display_full();
		void set_index( int i );
		int	get_index();
		std::string get_first_name();
};

#endif