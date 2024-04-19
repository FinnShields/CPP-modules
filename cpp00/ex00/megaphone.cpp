/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 08:00:16 by fshields          #+#    #+#             */
/*   Updated: 2024/04/05 13:49:55 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( int argc, char *argv[] )
{
	int		i;
	int		j;
	
	i = 0;
	j = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (j < argc)
	{
		while (argv[j][i])
		{
			if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
				std::cout << (unsigned char) toupper(argv[j][i]);
			else
				std::cout << argv[j][i];
			i++;
		}
		j ++;
		i = 0;
		if (j < argc)
			std::cout << ' ';
		else
			std::cout << std::endl;
	}
	return (0);
}