/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:27:47 by welow             #+#    #+#             */
/*   Updated: 2025/02/28 13:58:16 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef CALL
#define CALL 0
#endif

/**
 * 	private vs protected
 * @note 1. private: only able to access within the class, can't access by derived class
 * @note 2. protected: able to access within the class and also able to access by derived class
 *
 * @note 1.static: shared by all instances of the class
 * @note 2. const: only for read-only
*/
class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoint;
		unsigned int	_energyPoint;
		unsigned int	_attackDamage;
		static unsigned int const	_ClapTrapHitPoint = 10;
		static unsigned int const	_ClapTrapEnergyPoint = 10;
		static unsigned int const	_ClapTrapAttackDamage = 0;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &src);
		~ClapTrap(void);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		std::string		getName(void) const;
		unsigned int	getHitPoint(void) const;
		unsigned int	getEnergyPoint(void) const;
		unsigned int	getAttackDamage(void) const;
};