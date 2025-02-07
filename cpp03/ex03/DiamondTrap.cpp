/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 07:51:45 by welow             #+#    #+#             */
/*   Updated: 2025-02-06 07:51:45 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**
 * 1. DiamondTrap inherits from both ScavTrap and FragTrap.
 * 2. Both ScavTrap and FragTrap inherit from ClapTrap, so two copies of 
 *    ClapTrap exist in DiamondTrap.
 * 3. Now, DiamondTrap has two separate _hitPoint variables, one from ScavTrap 
 *    and one from FragTrap.
 * 
 * When you try to access _hitPoint in DiamondTrap, the compiler does not know 
 * which one you mean, leading to the "ambiguous" error.
 * 
 * SOLVE: implement "virtual inheritance" in FragTrap and ScavTrap class
 * "virtual inheritance" : Only one shared copy of ClapTrap
*/
DiamondTrap::DiamondTrap(void)
    : ClapTrap(), 
    FragTrap(), 
    ScavTrap()
{
    if (CALL == 1)
        std::cout << MAGENTA << "DiamondTrap (default constructor) called" << RESET << std::endl;
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), 
    FragTrap(name),
    ScavTrap(name) 
{
    if (CALL == 1)
        std::cout << MAGENTA << "DiamondTrap (constructor) called" << RESET << std::endl;
    this->_name = name;
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
    : ClapTrap(src),
    FragTrap(src),
    ScavTrap(src)
{
    if (CALL == 1)
        std::cout << MAGENTA << "DiamondTrap (copy constructor) called" << RESET << std::endl;
    *this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
    if (CALL == 1)
		std::cout << MAGENTA << "DiamondTrap (assignment operator) called" << RESET << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoint = src._hitPoint;
		this->_energyPoint = src._energyPoint;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    if (CALL == 1)
        std::cout << MAGENTA << "DiamondTrap (destructor) called" << RESET << std::endl;
}


void    DiamondTrap::whoAmI(void)
{
    if (this->_hitPoint == 0)
		std::cout <<  "DiamondTrap [" << this->_name << "] is already dead" << std::endl;
	else
		std::cout <<  "DiamondTrap is [" << this->_name << "] and Claptrap is [" << ClapTrap::_name << "]" << std::endl;
}