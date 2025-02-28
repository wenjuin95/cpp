/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:45 by welow             #+#    #+#             */
/*   Updated: 2025/02/28 14:09:20 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define CYAN "\033[36m"

void display_bot(DiamondTrap &bot1, DiamondTrap &bot2);

int main(void)
{
	DiamondTrap bot1("d-1");
	DiamondTrap bot2("d-2");

	std::cout << "=============================================================================" << std::endl << std::endl;
	{
		std::cout << "---------- DISPLAY ---------" << std::endl << std::endl;
		DiamondTrap diamondtrap1(bot1);
		DiamondTrap diamondtrap2(bot2);

		display_bot(diamondtrap1, diamondtrap2);
		std::cout << std::endl;

		std::cout << "---------- diamondtrap1 vs diamondtrap2 ---------" << std::endl << std::endl;
		diamondtrap1.attack(diamondtrap2.getName());
		display_bot(diamondtrap1, diamondtrap2);
		std::cout << std::endl;

		diamondtrap2.takeDamage(diamondtrap1.getAttackDamage());
		display_bot(diamondtrap1, diamondtrap2);
		std::cout << std::endl;

		std::cout << "---------- diamondtrap ability ---------" << std::endl << std::endl;
		diamondtrap1.whoAmI();
		diamondtrap2.whoAmI();
	}
	std::cout << "=============================================================================" << std::endl << std::endl;
}

void display_bot(DiamondTrap &bot1, DiamondTrap &bot2)
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