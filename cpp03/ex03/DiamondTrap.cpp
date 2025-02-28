/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:51:45 by welow             #+#    #+#             */
/*   Updated: 2025/02/28 13:41:37 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**
 * @note 1. DiamondTrap inherits from both FragTrap and ScavTrap.
 * @note 2. Both FragTrap and ScavTrap inherit from ClapTrap, so two copies of
 *			ClapTrap exist in DiamondTrap.
 * @note 3. Now, DiamondTrap has two separate "_hitPoint" variables, one from ScavTrap
 *			and one from FragTrap.
 * @note 4. When you try to access _hitPoint in DiamondTrap, the compiler does not know
 *			which one you mean, leading to the "ambiguous" error.

 * SOLVE: implement "virtual inheritance" in FragTrap and ScavTrap class
 			"virtual inheritance" : Only one shared copy of ClapTrap
*/

/**
 * @brief a default constructor
 * @note 1. FragTrap::hitPoint, ScavTrap::energyPoint, FragTrap::attackDamage is the value belong to each class
 */
DiamondTrap::DiamondTrap(void)
    : ClapTrap(), FragTrap(), ScavTrap()
{
    if (CALL == 1)
		std::cout << BLUE_H << "DiamondTrap (default constructor) called" << RESET << std::endl;
	this->_name = "Default";
	ClapTrap::_name = "Default_clap_name";
	this->_hitPoint = FragTrap::_FragTrapHitPoint;
	this->_energyPoint = ScavTrap::_ScavTrapEnergyPoint;
	this->_attackDamage = FragTrap::_FragTrapAttackDamage;
}

/**
 * @brief a constructor
 * @param name name of object
 * @note 1. Claptrap name must + "_clap_name" (pdf require)
 * @note 2. FragTrap::hitPoint, ScavTrap::energyPoint, FragTrap::attackDamage is the value belong to each class
*/
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    if (CALL == 1)
		std::cout << BLUE_H << "DiamondTrap (constructor) called" << RESET << std::endl;
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
    this->_hitPoint = FragTrap::_FragTrapHitPoint;
    this->_energyPoint = ScavTrap::_ScavTrapEnergyPoint;
    this->_attackDamage = FragTrap::_FragTrapAttackDamage;
}

/**
 * @brief a copy constructor
 * @param src object to copy
*/
DiamondTrap::DiamondTrap(const DiamondTrap &src)
    : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
    if (CALL == 1)
        std::cout << BLUE_H << "DiamondTrap (copy constructor) called" << RESET << std::endl;
    *this = src;
}

/**
 * @brief a assignment operator
 * @param src object to copy
 * @return object
*/
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
    if (CALL == 1)
		std::cout << BLUE_H << "DiamondTrap (assignment operator) called" << RESET << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoint = src._hitPoint;
		this->_energyPoint = src._energyPoint;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

/**
 * @brief a destructor
*/
DiamondTrap::~DiamondTrap(void)
{
    if (CALL == 1)
        std::cout << BLUE_H << "DiamondTrap (destructor) called" << RESET << std::endl;
}

void    DiamondTrap::whoAmI(void)
{
    if (this->_hitPoint == 0)
		std::cout <<  "DiamondTrap [" << this->_name << "] is already dead" << std::endl;
	else
		std::cout <<  "DiamondTrap is [" << this->_name << "] and Claptrap is [" << ClapTrap::_name << "]" << std::endl;
}
