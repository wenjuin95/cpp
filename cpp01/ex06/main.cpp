/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:34:35 by welow             #+#    #+#             */
/*   Updated: 2024/12/27 13:19:23 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static char *ft_toupper(char *str)
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
		std::cout << "Usage ./harlFilter [ DEBUG | INFO | WARNING | ERROR ]"
		<< std::endl;
		return (1);
	}
	harl.complain(ft_toupper(av[1]));
	return (0);
}
