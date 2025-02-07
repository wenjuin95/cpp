/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:51:23 by welow             #+#    #+#             */
/*   Updated: 2025/01/24 11:51:45 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	if (CALL == 1)
		std::cout << VIOLET << "ScavTrap (default constructor) called" << RESET << std::endl;
	this->_name = "";
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	if (CALL == 1)
		std::cout << VIOLET << "ScavTrap (constructor) called" << RESET << std::endl;
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	if (CALL == 1)
		std::cout << VIOLET << "ScavTrap (copy constructor) called" << RESET << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (CALL == 1)
		std::cout << VIOLET << "ScavTrap (assignment operator) called" << RESET << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoint = src._hitPoint;
		this->_energyPoint = src._energyPoint;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	if (CALL == 1)
		std::cout << VIOLET << "ScavTrap (destructor) called" << RESET << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->_hitPoint == 0)
		std::cout <<  "ScavTrap [" << this->_name << "] is already dead, can't guard the gate" << std::endl;
	else
		std::cout <<  "ScavTrap [" << this->_name << "] is now in Gate keeper mode" << std::endl;
}