/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:23:58 by welow             #+#    #+#             */
/*   Updated: 2025/01/08 17:21:00 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/**
 * @brief create human name without weapon
 * @param name human name
 * @note 1. in pdf humanB constructor should not have a weapon and not armed
 */
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << BLUE << "constructor HumanB: [ " << this->_name << " ] created without a weapon" << RESET << std::endl;
}

/**
 * @brief delete the human
 */
HumanB::~HumanB(void)
{
	std::cout << BLUE << "destuctor HumanB: [ " << this->_name << " ] destroyed" << RESET << std::endl;
}

/**
 * @brief set the weapon with object reference
 * @param weapon weapon object reference
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
	if (this->_weapon == NULL)
		std::cout << BLUE << "[ " << this->_name << " ] can't attack" << RESET << std::endl;
	else
		std::cout << BLUE << "[ "<< this->_name << " ] attacks with his [ " << RED << this->_weapon->getType() << BLUE << " ]" << RESET << std::endl;
}
