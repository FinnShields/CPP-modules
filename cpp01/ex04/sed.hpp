/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:04:01 by fshields          #+#    #+#             */
/*   Updated: 2024/04/08 12:55:50 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED
# define SED

# include <iostream>
# include <fstream>
# include <sstream>

int			error_message(std::string message, char *target);
std::string	make_new_name(char	*name);
void		ammend_str(std::string *content, char *str1, char *str2);

#endif