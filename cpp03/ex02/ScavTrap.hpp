/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:40:46 by welow             #+#    #+#             */
/*   Updated: 2025/02/28 14:03:26 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define RED_H "\033[41m"
#define RESET "\033[0m"

/**
 * @note 1. public inheritance
 * 			- public member => public
 * 			- protected member => protected
 * 			- private member => not accessible
 *
 * @note 2. protected inheritance
 * 			- public member => protected
 * 			- protected member => protected
 * 			- private member => not accessible
 *
 * @note 3. public inheritance
 * 			- public member => private
 * 			- protected member => private
 * 			- private member => not accessible
*/
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		ScavTrap &operator=(const ScavTrap &src);
		~ScavTrap(void);

		void attack(std::string const &target);
		void guardGate(void);
};

#endif