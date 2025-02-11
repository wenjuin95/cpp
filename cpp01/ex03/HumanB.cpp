/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:23:58 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:39:06 by welow            ###   ########.fr       */
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
	std::cout << "constructor HumanB: [ " << BLUE << this->_name << RESET << " ] created" << std::endl;
	if (this->_weapon == NULL || this->_weapon->getType().empty())
		std::cout << BLUE << "[ " << this->_name << " ] no weapon equip" << RESET << std::endl;
	else
		std::cout << BLUE << "[ " << this->_name << " ] equip [ "
			<< RED_H << this->_weapon->getType() << RESET <<  BLUE << " ] weapon" << RESET << std::endl;
}

/**
 * @brief delete the human
 */
HumanB::~HumanB(void)
{
	std::cout << "destuctor HumanB: [ " << BLUE << this->_name << RESET << " ] destroyed" << std::endl;
}

/**
 * @brief set the weapon with object reference
 * @param weapon weapon object reference
 */
void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	std::cout << BLUE << this->_name << " is now equipped with a [ " << RED_H << this->_weapon->getType() << BLUE << " ] weapon" << RESET << std::endl;
}

/**
 * @brief print the attack message
 */
void	HumanB::attack(void)
{
	if (this->_weapon == NULL || this->_weapon->getType().empty())
		std::cout << BLUE << "[ " << this->_name << " ] has no weapon can't attack" << RESET << std::endl;
	else
		std::cout << BLUE << "[ "<< this->_name << " ] attacks with his [ " << RED_H << this->_weapon->getType() << BLUE << " ]" << RESET << std::endl;
}
