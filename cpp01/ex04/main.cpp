/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:03:42 by fshields          #+#    #+#             */
/*   Updated: 2024/04/08 13:02:42 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int	main(int argc, char *argv[])
{
	std::fstream		file;
	std::string			new_file_name;
	std::string			file_content;
	std::stringstream	strStream;
	
	if (argc != 4)
		return (error_message("Format: [filename] [string_to_replace] [string_to_replace_with]", NULL));
	file.open(argv[1]);
	if (!file.is_open())
		return (error_message("Unable to open file: ", argv[1]));
	std::ofstream	new_file(make_new_name(argv[1]));
	strStream << file.rdbuf();
	file_content = strStream.str();
	if (file_content.find(argv[2]) != std::string::npos)
		ammend_str(&file_content, argv[2], argv[3]);
	file_content.begin();
	new_file << file_content;
	file.close();
	new_file.close();
	return (0);
}
