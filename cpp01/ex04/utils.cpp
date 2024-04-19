/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:16:03 by fshields          #+#    #+#             */
/*   Updated: 2024/04/08 13:27:15 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int	error_message(std::string message, char *target)
{
	if (!target)
		std::cout << message << std::endl;
	else
		std::cout << message << target << std::endl;
	return (1);
}

std::string	make_new_name(char	*name)
{
	std::string	new_name = name;
	new_name.append(".replace");
	return (new_name);
}

void	ammend_str(std::string *content, char *str1, char *str2)
{
	bool	is_second_string = true;
	if (!str1 || !*str1)
	{
		error_message("The first string is null or empty :(", NULL);
		return ;
	}
	if (!str2 || !*str2)
		is_second_string = false;
	std::string	s1 = str1;
	std::string s2;
	if (is_second_string)
		s2 = str2;
	size_t	pos = (*content).find(s1);
	while (pos != std::string::npos)
	{
		(*content).begin();
		(*content).erase(pos, s1.length());
		if (is_second_string)
			(*content).insert(pos, s2);
		pos = (*content).find(s1);
	}
}
