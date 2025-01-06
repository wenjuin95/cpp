/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:14:49 by welow             #+#    #+#             */
/*   Updated: 2025/01/06 11:47:58 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/**
 * @brief create human name and weapon name
 * @param name human name
 * @param weapon weapon object reference
 */
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << GREEN << "HumanA: [ " << this->_name << " ] created with [ "<< RED << this->_weapon.getType() << RESET <<  GREEN << " ]" << RESET << std::endl;
}

/**
 * @brief delete the human
 */
HumanA::~HumanA(void)
{
	std::cout << GREEN << "[ " << this->_name << " ] destroyed" << RESET << std::endl;
}

/**
 * @brief print the attack message
 */
void	HumanA::attack(void)
{
	std::cout << GREEN << "[ "<< this->_name << " ] attacks with thier [ "<< RED << this->_weapon.getType() << RESET <<  GREEN << " ]" << RESET << std::endl;
}


