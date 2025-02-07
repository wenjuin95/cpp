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
#include "FragTrap.hpp"

void display_bot(ClapTrap &bot1, ScavTrap &bot2, FragTrap &bot3)
{
    std::cout << std::left << CYAN << "Name: " << RESET << bot1.getName()
              << std::setw(25) << CYAN << "Name: " << RESET << bot2.getName()
              << std::setw(25) << CYAN << "Name: " << RESET << bot3.getName() << std::endl;

    std::cout << std::left << GREEN << "Hit Point: " << RESET << bot1.getHitPoint();
    std::cout << std::setw(21) << GREEN << "Hit Point: " << RESET << bot2.getHitPoint();
    std::cout << std::setw(20) << GREEN << "Hit Point: " << RESET << bot3.getHitPoint() << std::endl;

    std::cout << std::left << BLUE << "Energy Point: " << RESET << bot1.getEnergyPoint();
    std::cout << std::setw(18) << BLUE << "Energy Point: " << RESET << bot2.getEnergyPoint();
    std::cout << std::setw(18) << BLUE << "Energy Point: " << RESET << bot3.getEnergyPoint() << std::endl;

    std::cout << std::left << RED << "Attack Damage: " << RESET << bot1.getAttackDamage();
    std::cout << std::setw(18) << RED << "Attack Damage: " << RESET << bot2.getAttackDamage();
    std::cout << std::setw(17) << RED << "Attack Damage: " << RESET << bot3.getAttackDamage() << std::endl;
}

int main(void)
{
	//these both create one "Claptrap" constructor each
	ClapTrap botA("C-1");
	ScavTrap botB("S-1"); //Claptrap constructor -> Scavtrap constructor
	FragTrap botC("F-1"); //Claptrap constructor -> Fragtrap constructor

	std::cout << "=============================================================================" << std::endl << std::endl;
	{
		//this copy the "Claptrap" constructor to "Claptrap" constructor for each
		ClapTrap claptrap = botA;
		ScavTrap scavtrap = botB; //Claptrap copy constuctor -> Scavtrap copy constructor
		FragTrap fragtrap = botC; //Claptrap copy constuctor -> Fragtrap copy constructor

		std::cout << "CLAPTRAP                     SCAVTRAP                     FRAGTRAP" << std::endl;
		display_bot(claptrap, scavtrap, fragtrap);
		std::cout << std::endl;
		std::cout << "---------- claptrap vs scavtrap ---------" << std::endl;
		claptrap.attack("S-1");
		display_bot(claptrap, scavtrap, fragtrap);
		std::cout << std::endl;
		scavtrap.takeDamage(0);
		display_bot(claptrap, scavtrap, fragtrap);
		std::cout << std::endl;
		std::cout << "---------- claptrap vs fragtrap ---------" << std::endl;
		claptrap.attack("F-1");
		display_bot(claptrap, scavtrap, fragtrap);
		std::cout << std::endl;
		fragtrap.takeDamage(0);
		display_bot(claptrap, scavtrap, fragtrap);
		std::cout << std::endl;
	}
	std::cout << "=============================================================================" << std::endl << std::endl;
	{
		//this copy the "Claptrap" constructor to "Claptrap" constructor for each
		ClapTrap claptrap2 = botA;
		ScavTrap scavtrap2 = botB; //Claptrap copy constuctor -> Scavtrap copy constructor
		FragTrap fragtrap2 = botC; //Claptrap copy constuctor -> Fragtrap copy constructor

		std::cout << "CLAPTRAP                     SCAVTRAP                     FRAGTRAP" << std::endl;
		display_bot(claptrap2, scavtrap2, fragtrap2);
		std::cout << std::endl;
		std::cout << "---------- scavtrap vs claptrap ---------" << std::endl; //do anything here
		scavtrap2.attack("C-1");
		display_bot(claptrap2, scavtrap2, fragtrap2);
		std::cout << std::endl;
		claptrap2.takeDamage(20);
		display_bot(claptrap2, scavtrap2, fragtrap2);
		std::cout << std::endl;
		std::cout << "---------- scavtrap vs fragtrap ---------" << std::endl; //do anything here
		scavtrap2.attack("F-1");
		display_bot(claptrap2, scavtrap2, fragtrap2);
		std::cout << std::endl;
		fragtrap2.takeDamage(20);
		display_bot(claptrap2, scavtrap2, fragtrap2);
		std::cout << std::endl;	
		std::cout << "---------- scavtrap ability ---------" << std::endl;
		scavtrap2.guardGate();
		display_bot(claptrap2, scavtrap2, fragtrap2);
		std::cout << std::endl;	
	}
	std::cout << "=============================================================================" << std::endl << std::endl;
	{
		//this copy the "Claptrap" constructor to "Claptrap" constructor for each
		ClapTrap claptrap3 = botA;
		ScavTrap scavtrap3 = botB; //Claptrap copy constuctor -> Scavtrap copy constructor
		FragTrap fragtrap3 = botC; //Claptrap copy constuctor -> Fragtrap copy constructor

		std::cout << "CLAPTRAP                     SCAVTRAP                     FRAGTRAP" << std::endl;
		display_bot(claptrap3, scavtrap3, fragtrap3);
		std::cout << std::endl;
		std::cout << "---------- fragtrap vs claptrap ---------" << std::endl; //do anything here
		fragtrap3.attack("C-1");
		display_bot(claptrap3, scavtrap3, fragtrap3);
		std::cout << std::endl;
		claptrap3.takeDamage(30);
		display_bot(claptrap3, scavtrap3, fragtrap3);
		std::cout << std::endl;
		std::cout << "---------- fragtrap vs scavtrap ---------" << std::endl; //do anything here
		fragtrap3.attack("F-1");
		display_bot(claptrap3, scavtrap3, fragtrap3);
		std::cout << std::endl;
		scavtrap3.takeDamage(30);
		display_bot(claptrap3, scavtrap3, fragtrap3);
		std::cout << std::endl;
		std::cout << "---------- fragtrap ability ---------" << std::endl;
		fragtrap3.highFiveGuys();
		display_bot(claptrap3, scavtrap3, fragtrap3);
		std::cout << std::endl;	
	}
	std::cout << "=============================================================================" << std::endl << std::endl;
}