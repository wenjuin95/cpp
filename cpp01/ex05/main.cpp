/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:31:14 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:42:27 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/**
 * @brief Convert all lowercase characters in a string to uppercase
 * @param str The string to convert
 * @return The converted string
*/
static char *ftToupper(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "wrong argument" << std::endl;
		std::cout << "Usage ./harl [ DEBUG | INFO | WARNING | ERROR ]"
		<< std::endl;
		return (1);
	}
	harl.complain(ftToupper(av[1]));
	return 0;
}
