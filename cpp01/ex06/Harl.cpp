/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:39:45 by welow             #+#    #+#             */
/*   Updated: 2024/12/27 13:24:59 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug(void)
{
	std::cout << BLUE << "[ DEBUG ]    ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-"
	"triple-pickle-special-ketchup burger. I really do!" << RESET << std::endl;
}

void	Harl::_info(void)
{
	std::cout << GREEN << "[ INFO ]     ";
	std::cout << "I cannot believe adding extra bacon costs more money. You"
	" didn't put enough bacon in my burger! If you did, I wouldn't be asking"
	" for more" << RESET << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << YELLOW << "[ WARNING ]  ";
	std::cout << "I think I deserve to have some extra bacon for free."
	"I've been coming for years whereas you started working here since last "
	"month." << RESET << std::endl;
}

void	Harl::_error(void)
{
	std::cout << RED << "[ ERROR ]    ";
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< RESET << std::endl;
}

/**
 * @brief Print the message based on the level
 * @param level The level of the message
*/
void	Harl::complain( std::string level )
{
	std::string	level_lst[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int			i;

	i = 0;
	while (i < 4)
	{
		if (level == level_lst[i])
		{
			switch(i)
			{
				case 0:
					this->_debug();
					break ;
				case 1:
					this->_info();
					break ;
				case 2:
					this->_warning();
					break ;
				case 3:
					this->_error();
					break ;
			}
			return ;
		}
		i++;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
