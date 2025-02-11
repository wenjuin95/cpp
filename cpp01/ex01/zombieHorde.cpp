/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:05:41 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:37:32 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a horde of zombies
 * @param N Number of zombies
 * @param name Name of the zombies
 * @return pointer of the each zombie in the horde
 * @note 1. "new Zombie[N]" will only create a default constructor,
 * 		 you can't create a constructor with parameters
 */
Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		horde[i].setZombieName(name);
		i++;
	}
	return (horde);
}