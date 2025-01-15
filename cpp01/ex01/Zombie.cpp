/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:09:33 by welow             #+#    #+#             */
/*   Updated: 2025/01/15 12:10:17 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief a default constructor
 * @note 1. default constructor is to make an array of objects
 * @note 2. to memory allocate array of object must have a default constructor
*/
Zombie::Zombie(void)
{
    std::cout << "zombie is created" << std::endl;
}

/**
 * @brief a destructor
 * @note 1. this will be called when the object is destroyed
 * @note 2. when object use "delete" keyword, it will call the destructor
 */
Zombie::~Zombie(void)
{
    std::cout << "zombie is destroyed" << std::endl;
}

/**
 * @brief set the zombie name
 * @param name zombie name
*/
void    Zombie::setZombieName(std::string name)
{
    this->_zombieName = name;
}

/**
 * @brief get the zombie name
 * @return zombie name
 */
std::string Zombie::getZombieName(void)
{
    return this->_zombieName;
}

/**
 * @brief zombie calls out
 */
void    Zombie::announce(void)
{
    std::cout << this->_zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
