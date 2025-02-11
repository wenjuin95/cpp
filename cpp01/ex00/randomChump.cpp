/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:15:40 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:35:48 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a Zombie object and announce it
 * @param name name of the zombie
 */
void    randomChump(std::string name)
{
    Zombie chump = Zombie(name);
    chump.announce();
}