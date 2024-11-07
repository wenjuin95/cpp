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

using namespace std;

namespace ft_toupper
{
	char convert(char c)
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
		return (c);
	}
}

namespace ft_default
{
	char convert(char c)
	{
		if (c >= 'A' && c <= 'Z')
			return (c);
		return (c);
	}
}

int main(int ac, char **av)
{
	int i;
	int j;
	char c;

	if (ac != 1)
	{	
		i = 1;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
                c = av[i][j];
                if (c >= 'a' && c <= 'z') {
                    cout << ft_toupper::convert(c);
                } else if (c >= 'A' && c <= 'Z') {
                    cout << ft_default::convert(c);
                } else {
                    cout << c;
                }
				j++;
			}
			i++;
		}
	}
	else
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return 0;
}
