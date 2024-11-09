/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-09 09:08:37 by welow             #+#    #+#             */
/*   Updated: 2024-11-09 09:08:37 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a zombie object with memory allocation
 * @name zombieName name of the zombie
 * @return Zombie object
 */
Zombie  *newZombie(std::string zombieName)
{
    Zombie  *NewZombie = new Zombie(zombieName);
    return NewZombie;
}