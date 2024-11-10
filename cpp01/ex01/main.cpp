/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-10 11:12:03 by welow             #+#    #+#             */
/*   Updated: 2024-11-10 11:12:03 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int     numberOfZombies;
    Zombie  *newZombie;
    int     i;

    numberOfZombies = 5;
    newZombie = zombieHorde(numberOfZombies, "Cat");
    i = 0;
    while (i < numberOfZombies)
    {
        newZombie[i].announce();
        i++;
    }
    delete []newZombie;
    return (0);
}