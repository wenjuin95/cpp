/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:14:49 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:38:46 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
/**
 * @brief create human name and weapon name
 * @param name human name
 * @param weapon weapon object reference
 * @note 1. in pdf humanA constructor should have a weapon and armed
 */
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "constructor HumanA: [ " << GREEN << this->_name << RESET << " ] created" << std::endl;
	std::cout << GREEN << "[ " << this->_name << " ] equip with [ "<< RED_H << this->_weapon.getType() << RESET <<  GREEN << " ] weapon" << RESET << std::endl;
}

/**
 * @brief delete the human
 */
HumanA::~HumanA(void)
{
	std::cout << "destructor HumanA: [ " << GREEN << this->_name << RESET << " ] destroyed" << std::endl;
}

/**
 * @brief print the attack message
 */
void	HumanA::attack(void)
{
	if (this->_weapon.getType().empty())
		std::cout << GREEN << "[ "<< this->_name << " ] has no weapon can't attack" << RESET << std::endl;
	else
		std::cout << GREEN << "[ "<< this->_name << " ] attacks with his [ "<< RED_H << this->_weapon.getType() << RESET <<  GREEN << " ]" << RESET << std::endl;
}
