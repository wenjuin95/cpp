/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:23:58 by welow             #+#    #+#             */
/*   Updated: 2025/01/01 23:41:02 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/**
 * @brief create human name without weapon
 * @param name human name
 */
HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << BLUE << "HumanB: [ " << this->_name << " ] created without a weapon" << RESET << std::endl;
}

/**
 * @brief delete the human
 */
HumanB::~HumanB(void)
{
	std::cout << BLUE << this->_name << " destroyed" << RESET << std::endl;
}


/**
 * @brief set the weapon with object reference
 * @param weapon weapon object reference
 * @note if you remove & from the Weapon parameter, it will call the copy constructor
 */
void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	std::cout << BLUE << this->_name << " is now equipped with a [ " << RED << this->_weapon->getType() << BLUE << " ]" << RESET << std::endl;
}

/**
 * @brief print the attack message
 */
void	HumanB::attack(void)
{
	std::cout << BLUE << this->_name << " attacks with their [ " << RED << this->_weapon->getType() << BLUE << " ]" << RESET << std::endl;
}
