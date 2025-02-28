/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:45 by welow             #+#    #+#             */
/*   Updated: 2025/02/28 13:15:32 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define CYAN "\033[36m"

void display_bot(FragTrap &bot1, FragTrap &bot2);
void display_3bot(ClapTrap &bot1, ScavTrap &bot2, FragTrap &bot3);

int main(void)
{
	FragTrap botA("F-1");
	FragTrap botB("F-2");

	std::cout << "=============================================================================" << std::endl << std::endl;
	{
		FragTrap fragtrap(botA);
		FragTrap fragtrap2(botB);

		std::cout << "---------- DISPLAY ----------" << std::endl << std::endl;
		display_bot(fragtrap, fragtrap2);
		std::cout << std::endl;

		std::cout << "---------- start ----------" << std::endl << std::endl;
		fragtrap.attack(fragtrap2.getName());
		display_bot(fragtrap, fragtrap2);
		std::cout << std::endl;

		fragtrap2.takeDamage(fragtrap.getAttackDamage());
		display_bot(fragtrap, fragtrap2);
		std::cout << std::endl;

		fragtrap2.beRepaired(5);
		display_bot(fragtrap, fragtrap2);
		std::cout << std::endl;

		std::cout << "---------- fragtrap ability ----------" << std::endl << std::endl;
		fragtrap.highFiveGuys();
	}
	std::cout << "=============================================================================" << std::endl << std::endl;
	{
		ClapTrap claptrap("Claptrap");
		ScavTrap scavtrap("Scavtrap");
		FragTrap fragtrap("Fragtrap");

		std::cout << "---------- DISPLAY ----------" << std::endl << std::endl;
		display_3bot(claptrap, scavtrap, fragtrap);
	}
	std::cout << "=============================================================================" << std::endl << std::endl;
}

void display_bot(FragTrap &bot1, FragTrap &bot2)
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

void display_3bot(ClapTrap &bot1, ScavTrap &bot2, FragTrap &bot3)
{
	std::cout << CYAN "Name: (" RESET << bot1.getName() << CYAN ") " RESET
	GREEN "hit_point (" RESET << bot1.getHitPoint() << GREEN ") " RESET
	BLUE "energy_point(" RESET << bot1.getEnergyPoint() << BLUE ") " RESET
	RED "attack_damage(" RESET << bot1.getAttackDamage() << RED ")" RESET << std::endl;

	std::cout << CYAN "Name: (" RESET << bot2.getName() << CYAN ") " RESET
	GREEN "hit_point (" RESET << bot2.getHitPoint() << GREEN ") " RESET
	BLUE "energy_point(" RESET << bot2.getEnergyPoint() << BLUE ") " RESET
	RED "attack_damage(" RESET << bot2.getAttackDamage() << RED ")" RESET << std::endl;

	std::cout << CYAN "Name: (" RESET << bot3.getName() << CYAN ") " RESET
	GREEN "hit_point (" RESET << bot3.getHitPoint() << GREEN ") " RESET
	BLUE "energy_point(" RESET << bot3.getEnergyPoint() << BLUE ") " RESET
	RED "attack_damage(" RESET << bot3.getAttackDamage() << RED ")" RESET << std::endl;
}