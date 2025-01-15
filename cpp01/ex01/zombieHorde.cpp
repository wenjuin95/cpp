/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:05:41 by welow             #+#    #+#             */
/*   Updated: 2025/01/15 12:08:17 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a horde of zombies
 * @param N Number of zombies
 * @param name Name of the zombies
 * @return Zombie*
 */
Zombie* zombieHorde(int N, std::string name)
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