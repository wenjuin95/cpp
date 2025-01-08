/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:59:25 by welow             #+#    #+#             */
/*   Updated: 2025/01/08 16:50:17 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/**
 * @brief create a weapon
 * @param type weapon type
 */
Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << RED << "constructor weapon: [ "<< this->_type << " ] created" << RESET << std::endl;
}

/**
 * @brief delete the weapon
 */
Weapon::~Weapon(void)
{
	std::cout << RED << "destructor weapon: [ " << this->_type << " ] destroyed" << RESET << std::endl;
}

/**
 * @brief get the weapon type with the object reference
 * @return weapon type
 * @note 1. "const &" is to get the value of the object without changing it
 * @note 2. if you remove & from the Weapon parameter, it will call the copy constructor
 */
std::string const	&Weapon::getType(void) const
{
	return (this->_type);
}

/**
 * @brief set the weapon type
 * @param type weapon type
 */
void	Weapon::setType(std::string type)
{
	this->_type = type;
	std::cout << "[ " << RED << this->_type << RESET << " ] changed" << std::endl;
}
