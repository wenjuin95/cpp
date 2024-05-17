/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:44:15 by welow             #+#    #+#             */
/*   Updated: 2024/05/17 17:44:15 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char ft_toupper(char c);

int main(int ac, char **av)
{
	int i;
	int j;

	if (ac != 1)
	{	
		i = 1;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				std::cout << ft_toupper(av[i][j]);
				j++;
			}
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}

char ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}