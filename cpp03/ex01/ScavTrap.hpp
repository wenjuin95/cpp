/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:40:46 by welow             #+#    #+#             */
/*   Updated: 2025/01/24 11:49:48 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap(void);
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		ScavTrap &operator=(const ScavTrap &src);
		~ScavTrap(void);
		void attack(const std::string &target);
		void guardGate(void);
};

#endif