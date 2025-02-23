/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:00:54 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:36:10 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief a contructor
 * @note 1. "_zombieName(zombieName)" is an initialization list (initialization of member variables)
 */
Zombie::Zombie(std::string zombieName)
{
	this->_zombieName = zombieName;
	std::cout << this->getZombieName() << " (constructor) is created" << std::endl;
}

/**
 * @brief a destructor
 * @note 1. this will be called when the object is destroyed
 * @note 2. when object use "delete" keyword, it will call the destructor
 */
Zombie::~Zombie(void)
{
	std::cout << this->getZombieName() << " (destructor) is destroyed" << std::endl;
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
