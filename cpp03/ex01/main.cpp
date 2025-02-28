/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:45 by welow             #+#    #+#             */
/*   Updated: 2025/02/28 13:15:47 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define CYAN "\033[36m"

void display_bot(ScavTrap &bot1, ScavTrap &bot2);

int main(void)
{
	ScavTrap botA("S-1");
	ScavTrap botB("S-2");

	std::cout << "=======================================================================" << std::endl;
	{
		ScavTrap scavtrap = botA;
		ScavTrap scavtrap2 = botB;

		std::cout << "---------- DISPLAY ----------" << std::endl << std::endl;
		display_bot(scavtrap, scavtrap2);
		std::cout << std::endl;

		std::cout << "---------- start ---------" << std::endl << std::endl;
		scavtrap.attack(scavtrap2.getName());
		display_bot(scavtrap, scavtrap2);
		std::cout << std::endl;

		scavtrap2.takeDamage(scavtrap.getAttackDamage());
		display_bot(scavtrap, scavtrap2);
		std::cout << std::endl;

		scavtrap2.beRepaired(5);
		display_bot(scavtrap, scavtrap2);
		std::cout << std::endl;

		std::cout << "---------- sravtrap ability ---------" << std::endl << std::endl;
		scavtrap.guardGate();
	}
	std::cout << "=======================================================================" << std::endl;
}

void display_bot(ScavTrap &bot1, ScavTrap &bot2)
{
	std::cout << CYAN "Name: (" RESET << bot1.getName() << CYAN ") " RESET
		GREEN "hit_point (" RESET << bot1.getHitPoint() << GREEN ") " RESET
		BLUE "energy_point(" RESET << bot1.getEnergyPoint() << BLUE ") " RESET
		RED "attack_damage(" RESET << bot1.getAttackDamage() << RED ")" RESET << std::endl;

	std::cout << CYAN "Name: (" RESET << bot2.getName() << CYAN ") " RESET
		GREEN "hit_point (" RESET << bot2.getHitPoint() << GREEN ") " RESET
		BLUE "energy_point(" RESET << bot2.getEnergyPoint() << BLUE ") " RESET
		RED "attack_damage(" RESET << bot2.getAttackDamage() << RED ")" RESET << std::endl;
}