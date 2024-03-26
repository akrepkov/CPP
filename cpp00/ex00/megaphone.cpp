/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:17:54 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/24 15:43:19 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl;
	else
	{
		while(argv[i])
		{
			j = -1;
			while(argv[i][++j])
			{	
				if (typeid(argv[i][j]) == typeid(char))
					std::cout << (char)toupper(argv[i][j]);
				else
					std::cout << argv[i][j];
			}
			i++;
			if (argv[i] != NULL)
				std::cout << " ";
		}
	}
	return (0);
}
