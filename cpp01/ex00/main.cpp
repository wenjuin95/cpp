/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:18:51 by welow             #+#    #+#             */
/*   Updated: 2025/01/14 11:34:56 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    //have memory allocation
    Zombie  *zombie1 = newZombie("Zombie1 (with memory)");
    zombie1->announce();
    // delete zombie1;

	std::cout << std::endl;

    //no memory allocation
    randomChump("Zombie1 (no memory)");

    return 0;
}