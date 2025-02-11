/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:28:27 by welow             #+#    #+#             */
/*   Updated: 2025/02/11 14:40:08 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	/**
	 * 1. Alway valid :: must be initialize when the "HumanA" is created and cannot be null.
	 * ensure
	*/
	{
		std::cout << "----------REFERENCE----------" << std::endl;
		{
			Weapon club = Weapon("crude spiked club");

			HumanA bob("Bob", club);
			bob.attack();
			club.setType("some other type of club");
			bob.attack();
		}
	}
	/*
	* 1. When you want the flexibility to change the Weapon object during the lifetime of the HumanB object.
	* 2. The pointer can be null, which allows HumanB to exist without a weapon initially.
	* NOTE :: when the Weapon object might not always be available or might change frequently.
	*/
	std::cout << std::endl;
	{
		std::cout << "----------POINTER----------" << std::endl;
		{
			Weapon club = Weapon("crude spiked club");

			HumanB jim("Jim");
			jim.attack();
			jim.setWeapon(club);
			jim.attack();
			club.setType("some other type of club");
			jim.attack();
		}
	}
	/*
	* POINTER
	* 1. the object should always have a valid reference to another object.
	* REFERENCE
	* 1. the object might not always have a valid reference
	* 2. when you need the flexibility to change the reference during the object's lifetime.
	*/
	std::cout << "==================================================================================" << std::endl << std::endl;
	{
		std::cout << "---------- when no weapon equip by humanA and humanB ----------" << std::endl;
		std::cout << "----------REFERENCE----------" << std::endl;
		Weapon club = Weapon("");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Dagger");
		bob.attack();
	}
	std::cout << std::endl;
	{
		std::cout << "----------POINTER----------" << std::endl;
		Weapon club = Weapon("");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("Dagger");
		jim.attack();
	}
	return 0;
}
