/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:55:01 by welow             #+#    #+#             */
/*   Updated: 2025/01/17 17:54:09 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	if (CALL == 1)
		std::cout << "ClapTrap (default constructor) called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	if (CALL == 1)
		std::cout << this->_name << " (constructor) called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	if (CALL == 1)
		std::cout << "ClapTrap (copy constructor) called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	if (CALL == 1)
		std::cout << "ClapTrap (assignment operator) called" << std::endl;
	this->_name = src.getName();
	this->_hitPoint = src.getHitPoint();
	this->_energyPoint = src.getEnergyPoint();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	if (CALL == 1)
		std::cout << this->_name << " (destructor) called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if ( this->_energyPoint > 0 && this->_hitPoint > 0)
	{
		this->_energyPoint--;
		std::cout << "[" << this->_name << "] attacks [" << target
				<< "], causing [" << this->_attackDamage
				<< "] hit point of damage!" << std::endl;
		std::cout << this->_name << " energy point left " << this->_energyPoint << std::endl << std::endl; //debug energy point
	}
	if (this->_hitPoint == 0 || this->_energyPoint == 0)
	{
		std::cout <<  "[" << this->_name << "] can't attack" << std::endl;
		std::cout << this->_name << " energy point left " << this->_energyPoint << std::endl << std::endl; //debug energy point
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint > amount)
		this->_hitPoint -= amount;
	else if (this->_hitPoint > 0)
		this->_hitPoint = 0;
	else
	{
		std::cout << "[" << this->_name << "] is dead" << std::endl;
		std::cout << this->_name << " hit point left " << this->_hitPoint << std::endl << std::endl; //debug hit point
		return ;
	}
	std::cout << "[" << this->_name << "] take [" << amount
			<< "] hit point of damage!" << std::endl;
	std::cout << this->_name << " hit point left " << this->_hitPoint << std::endl <<; //debug hit point
}

void ClapTrap::beRepaired(int amount)
{
	if (amount < 0)
	{
		std::cout << "amount can't accept negative value" << std::endl;
		return ;
	}
	if (this->_hitPoint == 10)
	{
		std::cout << "[" << this->_name << "] already have full hit point" << std::endl;
		return ;
	}
	if (this->_energyPoint > 0 && this->_hitPoint > 0 && this->_hitPoint + amount <= 10)
	{
		this->_hitPoint += amount;
		std::cout << "[" << this->_name << "] use an energy point to repaired and gain [" << amount
				<< "] of hit point!" << std::endl;
		this->_energyPoint--;
		std::cout << this->_name << " energy point left " << this->_energyPoint << std::endl; //debug energy point
	}
	else if (this->_hitPoint + amount > 10 && this->_hitPoint <= 10)
		std::cout << "[" << this->_name << "] can't be repair because " << amount << " is too big (must be "
				<< amount - this->_hitPoint << ")" << std::endl;
	else if (this->_hitPoint == 0 || this->_energyPoint == 0)
		std::cout << "[" << this->_name << "] already died, can't be repaired" << std::endl;
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoint(void) const
{
	return (this->_hitPoint);
}

unsigned int	ClapTrap::getEnergyPoint(void) const
{
	return (this->_energyPoint);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}
