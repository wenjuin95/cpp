/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:45 by welow             #+#    #+#             */
/*   Updated: 2025/02/28 13:42:06 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

void display_bot(ClapTrap &bot1, ClapTrap &bot2);

int main(void)
{
	std::string bot1 = "A-1";
	std::string bot2 = "B-2";

	ClapTrap botA(bot1);
	ClapTrap botB(bot2);

	std::cout << "==========================================================" << std::endl;
	{
		ClapTrap claptrap1(botA);
		ClapTrap claptrap2(botB);

		std::cout << "CLAPTRAP1                    CLAPTRAP2" << std::endl;
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

		claptrap1.attack(claptrap2.getName());
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

		claptrap2.takeDamage(claptrap1.getAttackDamage());
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

		claptrap2.beRepaired(5);
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

	}
	std::cout << "==========================================================" << std::endl << std::endl;
	{
		ClapTrap claptrap1(botA);
		ClapTrap claptrap2(botB);

		claptrap2.attack(claptrap1.getName());
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

		claptrap2.takeDamage(claptrap2.getAttackDamage());
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

		claptrap2.beRepaired(5);
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;
	}
	std::cout << "=======================================================================" << std::endl;
}

void display_bot(ClapTrap &bot1, ClapTrap &bot2)
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