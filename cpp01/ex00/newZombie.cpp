/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:08:37 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:35:38 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a zombie object with memory allocation
 * @param name name of the zombie
 * @return Zombie object
 */
Zombie  *newZombie(std::string name)
{
    Zombie  *NewZombie = new Zombie(name);
    return NewZombie;
}