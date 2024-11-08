/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:06:03 by welow             #+#    #+#             */
/*   Updated: 2024/11/01 17:07:45 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

std::string ftToupper(std::string str);
void MenuBar(void);

int main(void)
{
	Phonebook phonebook;
	std::string input;

	phonebook.index = 0;
	std::cout << std::endl << YELLOW << "\tWELCOME TO PHONEBOOK\t" << RESET;
	while (1)
	{
		MenuBar();
		std::getline(std::cin, input); // get the input from the user
		if (std::cin.eof())
			break;
		input = ftToupper(input);
		if(input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
			phonebook.SearchContact();
		else if (input == "EXIT")
		{
			std::cout << YELLOW << "\t--EXIT PHONEBOOK--\t" << RESET << std::endl;
			break;
		}
	}
	return (0);
}

/*
*	@brief display the main menu
*/
void	MenuBar(void)
{
	std::cout << "\n";
	std::cout << "+------------MAIN MENU------------+\n";
	std::cout << "| ADD: to add a new contact       |\n";
	std::cout << "| SEARCH: to search for a contact |\n";
	std::cout << "| EXIT: to exit the phonebook     |\n";
	std::cout << "+---------------------------------+\n";
	std::cout << "\rEnter your command (ADD, SEARCH, EXIT): ";
}

/*
*	ft_toupper :: convert the string to uppercase
*	@param: string
*	@return: string in uppercase
*/
std::string ftToupper(std::string str)
{
	std::string res;
	int i = 0;
	while (str[i])
	{
		res += toupper(str[i]);
		i++;
	}
	return (res);
}
