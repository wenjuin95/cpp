/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:37:57 by welow             #+#    #+#             */
/*   Updated: 2024/06/09 16:37:57 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*****************************CONSTRUCTOR*************************************/
Phonebook::Phonebook(void)
{
	_index = 0;
	// backdoor(); //show purpose
}

/******************************DESTRUCTOR*************************************/
Phonebook::~Phonebook(void) {}

/***************************CLASS FUNCTION************************************/
void	Phonebook::add_contact(void)
{
	Contact t_contact; //temporary "Contact" class to store the value
	std::string input;

	std::cout << "[ type BACK to return to main menu ]" << std::endl;
	if (_index > 7) //check if the index is more than 8 then set the index to 0
		_index = 0;
	input = get_input("Enter first name: ", 1);
	if (input.empty())
		return ;
	t_contact.set_first_name(input);
	input = get_input("Enter last name: ", 1);
	if (input.empty())
		return ;
	t_contact.set_last_name(input);
	input = get_input("Enter nick name: ", 1);
	if (input.empty())
		return ;
	t_contact.set_nickname(input);
	input = get_input("Enter phone number: ", 2);
	if (input.empty())
		return ;
	t_contact.set_phone_number(input);
	input = get_input("Enter dark secret: ", 3);
	if (input.empty())
		return ;
	t_contact.set_dark_secret(input);
	if (t_contact.get_first_name().empty() || t_contact.get_last_name().empty()
	|| t_contact.get_nickname().empty() || t_contact.get_phone_number().empty() 
	|| t_contact.get_dark_secret().empty()) //check if the input is empty
	{
		std::cout << RED << "Contact not added\n" << RESET;
		return;
	}
	else 
		_contact[_index++] = t_contact; //each of the contact will be store in the array
	std::cout << GREEN << "Contact added successfully\n" << RESET;
}

void	Phonebook::search_contact(void)
{
	int	i;
	std::string input;
	int index;

	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "FirstName";
	std::cout << "|" << std::setw(10) << "LastName";
	std::cout << "|" << std::setw(10) << "NickName" << "|" << std::endl;
	i = 0;
	while (i < 8)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << ft_truncated(_contact[i]. get_first_name());
		std::cout << "|" << std::setw(10) <<ft_truncated(_contact[i]. get_last_name());
		std::cout << "|" << std::setw(10) << ft_truncated(_contact[i]. get_nickname()) << "|" << std::endl;
		i++;
	}
	while (1)
	{
		std::cout << "[ type BACK to return to main menu ]" << std::endl;
		std::cout << "ENTER INDEX TO DISPLAY CONTACT [1 - 8]: ";
		std::getline(std::cin, input);
		if (input == "back")
			return ;
		if (input.empty()) //handle "enter"
		{
			std::cout << RED << "Input cannot be empty\n" << RESET;
			continue;
		}
		if (check_digit(input) == FALSE)
		{
			std::cout << RED << "Only digit allow\n" << RESET;
			continue;
		}
		index = atoi(input.c_str());
		if (index < 1 || index > 8)
		{
			std::cout << RED << "Index out of range\n" << RESET;
			continue;
		}
		std::cout << "----------Contact ["<< index << "]----------\n";
		std::cout << "First Name: "<< _contact[index - 1].get_first_name() << std::endl;
		std::cout << "Last Name: "<< _contact[index - 1].get_last_name() << std::endl;
		std::cout << "Nick Name: "<< _contact[index - 1].get_nickname() << std::endl;
		std::cout << "Phone Number: "<< _contact[index - 1].get_phone_number() << std::endl;
		std::cout << "Dark Secret: "<< _contact[index - 1].get_dark_secret() << std::endl << std::endl;
	}
}

/*****************************FUNCTION****************************************/

/*
*	@brief check if the input is an alphabet
*	@param str: input from the user
*	@return TRUE: if the input is an alphabet, FALSE: if the input is not an alphabet
*/
int check_alpha(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (isalpha(str[i]) == 0 && str[i] != ' ') // check if the character is not a letter and not a space
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
*	@brief check if the input is a digit
*	@param str: input from the user
*	@return TRUE: if the input is a digit, FALSE: if the input is not a digit
*/
int check_digit(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (isdigit(str[i]) == 0 && str[i] != ' ') // check if the character is not a digit and not a space
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
*	@brief function to get the input from the user
*	@param message: message to be set
*	@param handle_alphanum: 1 = alphabet, 2 = digit, 3 = alphabet and digit
*	@return input: return the input from the user input
*/
std::string get_input(std::string message, int handle_alphanum)
{
	std::string input;
	while (1)
	{
		std::cout << message;
		std::getline(std::cin, input);
		if (input == "back")
		{
			std::cout << RED << "Contact not added\n" << RESET;
			return ("");
		}
		if (input.empty()) //handle "enter"
		{
			std::cout << RED << "Input cannot be empty\n" << RESET;
			continue;
		}
		if (handle_alphanum == 1) //handle alphabet
		{
			if (check_alpha(input) == FALSE)
			{
				std::cout << RED << "Only alphabet allow\n" << RESET;
				continue;
			}
		}
		else if (handle_alphanum == 2) //handle digit
		{
			if (check_digit(input) == FALSE)
			{
				std::cout << RED << "Only digit allow\n" << RESET;
				continue;
			}
		
		}
		else if (handle_alphanum == 3) //handle alphabet and digit
		{
			if (check_alpha(input) == TRUE && check_digit(input) == TRUE)
				continue;
		}
		break;
	}
	return (input);
}

/*
*	@brief function to truncated the string
*	@param str: string to be truncated
*	@return str: return the truncated string
*/
std::string	ft_truncated(std::string str)
{
	if (str.length() > 10) //if the string more than 10 len
	{
		str.resize(9); //resize the string len to 9
		str.append("."); //add "." at the end of the string
	}
	return (str);
}

// //for input everything to it
// void	Phonebook::backdoor(void)
// {
// 	_contact[0].set_first_name("Wesley");
// 	_contact[0].set_last_name("Low");
// 	_contact[0].set_nickname("welow");
// 	_contact[0].set_phone_number("0123456789");
// 	_contact[0].set_dark_secret("I am a student at 42KL");

// 	_contact[1].set_first_name("John");
// 	_contact[1].set_last_name("Doe");
// 	_contact[1].set_nickname("johndoe");
// 	_contact[1].set_phone_number("9876543210");
// 	_contact[1].set_dark_secret("I am a student at 42KL");

// 	_contact[2].set_first_name("Jane");
// 	_contact[2].set_last_name("Doe");
// 	_contact[2].set_nickname("janedoe");
// 	_contact[2].set_phone_number("1234567890");
// 	_contact[2].set_dark_secret("I am a student at 42KL");

// 	_contact[3].set_first_name("John");
// 	_contact[3].set_last_name("Smith");
// 	_contact[3].set_nickname("johnsmith");
// 	_contact[3].set_phone_number("0987654321");
// 	_contact[3].set_dark_secret("I am a student at 42KL");

// 	_contact[4].set_first_name("Jane");
// 	_contact[4].set_last_name("Smith");
// 	_contact[4].set_nickname("janesmith");
// 	_contact[4].set_phone_number("1234567890");
// 	_contact[4].set_dark_secret("I am a student at 42KL");

// 	_contact[5].set_first_name("John");
// 	_contact[5].set_last_name("Doe");
// 	_contact[5].set_nickname("johndoe");
// 	_contact[5].set_phone_number("9876543210");
// 	_contact[5].set_dark_secret("I am a student at 42KL");

// 	_contact[6].set_first_name("Jane");
// 	_contact[6].set_last_name("Doe");
// 	_contact[6].set_nickname("janedoe");
// 	_contact[6].set_phone_number("1234567890");
// 	_contact[6].set_dark_secret("I am a student at 42KL");

// 	_contact[7].set_first_name("John");
// 	_contact[7].set_last_name("Smith");
// 	_contact[7].set_nickname("johnsmith");
// 	_contact[7].set_phone_number("0987654321");
// 	_contact[7].set_dark_secret("I am a student at 42KL");

// 	_index = 8;
// }