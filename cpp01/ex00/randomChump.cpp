/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-09 09:15:40 by welow             #+#    #+#             */
/*   Updated: 2024-11-09 09:15:40 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a Zombie object and announce it
 * @param zombieName name of the zombie
 */
void    randomChump(std::string zombieName)
{
    Zombie chump = Zombie(zombieName);
    chump.announce();
}