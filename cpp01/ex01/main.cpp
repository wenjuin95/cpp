/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:12:03 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:37:07 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int		numberOfZombies;
	Zombie	*newZombie;
	int		i;

	numberOfZombies = 5;
	newZombie = zombieHorde(numberOfZombies, "bug");
	i = 0;
	while (i < numberOfZombies)
	{
		std::cout << "No." << i + 1 << "-> ";
		newZombie[i].announce();
		i++;
	}
	delete []newZombie;
	return 0;
}