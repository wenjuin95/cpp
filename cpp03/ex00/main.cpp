/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:45 by welow             #+#    #+#             */
/*   Updated: 2025/01/17 17:53:08 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::string bot1 = "A-1";
	std::string bot2 = "B-2";

	ClapTrap a(bot1);
	ClapTrap b(bot2);

	a.attack(bot2);
	b.takeDamage(5);
	b.beRepaired(-10);
}