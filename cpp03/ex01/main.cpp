/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:45 by welow             #+#    #+#             */
/*   Updated: 2025/01/24 13:01:11 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void display_bot(ClapTrap &bot1, ClapTrap &bot2)
{
    std::cout << std::left << CYAN << "Name: " << RESET << bot1.getName()
              << std::setw(25) << CYAN << "Name: " << RESET << bot2.getName() << std::endl;

    std::cout << std::left << GREEN << "Hit Point: " << RESET << bot1.getHitPoint();
	if (bot1.getHitPoint() >= 10)
		std::cout << std::setw(21) << GREEN << "Hit Point: " << RESET << bot2.getHitPoint() << std::endl;
	else
		std::cout << std::setw(22) << GREEN << "Hit Point: " << RESET << bot2.getHitPoint() << std::endl;

    std::cout << std::left << BLUE << "Energy Point: " << RESET << bot1.getEnergyPoint();
	if (bot1.getEnergyPoint() >= 10)
		std::cout << std::setw(18) << BLUE << "Energy Point: " << RESET << bot2.getEnergyPoint() << std::endl;
	else
		std::cout << std::setw(19) << BLUE << "Energy Point: " << RESET << bot2.getEnergyPoint() << std::endl;

    std::cout << std::left << RED << "Attack Damage: " << RESET << bot1.getAttackDamage()
              << std::setw(18) << RED << "Attack Damage: " << RESET << bot2.getAttackDamage() << std::endl;
}

int main(void)
{
	//these both create one "Claptrap" constructor each
	ClapTrap botA("C-1");
	ScavTrap botB("S-1"); //then this create "Scavtrap" constructor

	{
		//this copy the "Claptrap" constructor to "Claptrap" constructor for each
		ClapTrap claptrap = botA;
		ScavTrap scavtrap = botB; //this copy the "Scavtrap" constructor to "Scavtrap" constructor 

		std::cout << "CLAPTRAP                     SCAVTRAP" << std::endl;
		display_bot(claptrap, scavtrap);
		std::cout << std::endl;
		std::cout << "---------- start ---------" << std::endl;
		claptrap.attack("S-1");
		display_bot(claptrap, scavtrap);
		std::cout << std::endl;
		scavtrap.takeDamage(0);
		display_bot(claptrap, scavtrap);
		std::cout << std::endl;
		scavtrap.beRepaired(5);
		display_bot(claptrap, scavtrap);
		std::cout << std::endl;

		std::cout << "==========================================================" << std::endl << std::endl;

		// this copy the "Claptrap" constructor to "Claptrap" constructor for each
		ClapTrap claptrap2 = botA;
		ScavTrap scavtrap2 = botB; //this copy the "Scavtrap" constructor to "Scavtrap" constructor

		scavtrap2.attack("C-1");
		display_bot(claptrap2, scavtrap2);
		std::cout << std::endl;
		claptrap2.takeDamage(20);
		display_bot(claptrap2, scavtrap2);
		std::cout << std::endl;
		claptrap2.beRepaired(5);
		display_bot(claptrap2, scavtrap2);
		std::cout << std::endl;
		scavtrap2.guardGate();
		display_bot(claptrap2, scavtrap2);
		std::cout << std::endl;

		std::cout << "=======================================================================" << std::endl;
	}
	//{
	//	std::cout << std::endl << "========== WHEN A-1 keep hit B-2" << std::endl;

	//	ClapTrap claptrap(botA);
	//	ScavTrap scavtrap(botB);

	//	display_bot(claptrap, scavtrap);
	//	std::cout << std::endl;
	//	for ( int i = 0; i <= 10; i++)
	//	{
	//		std::cout << "round " << i << std::endl;
	//		claptrap.attack(Sbot);
	//		display_bot(claptrap, scavtrap);
	//		std::cout << std::endl;
	//	}
	//	claptrap.takeDamage(10);
	//	display_bot(claptrap, scavtrap);
	//	std::cout << std::endl;

	//	claptrap.beRepaired(5);
	//	display_bot(claptrap, scavtrap);
	//	std::cout << std::endl;

	//	std::cout << "=======================================================================" << std::endl << std::endl;
	//}
}