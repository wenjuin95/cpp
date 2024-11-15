/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:59:25 by welow             #+#    #+#             */
/*   Updated: 2024/11/15 18:28:21 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/**
 * @brief create a weapon
 * @param type weapon type
 */
Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << RED << "[ "<< this->_type << " ] created" << RESET << std::endl;
}

/**
 * @brief delete the weapon
 */
Weapon::~Weapon(void)
{
	std::cout << RED << "[ " << this->_type << " ] destroyed" << RESET << std::endl;
}

/**
 * @brief get the weapon type with the object reference
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
