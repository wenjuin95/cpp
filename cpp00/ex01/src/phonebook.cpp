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

/*
*	@brief add the contact to the phonebook
*	@param t_contract: contact to be added to the phonebook
*	@return contract added successfully
*	@note 1. if the index is more than 8 then set the index to 0
*	@note 2. each of the contact will be store in the array
*/
void	Phonebook::AddContact(void)
{
	Contact t_contact;
	std::string input;

	index = 0;
	std::cout << "====================================" << std::endl;
	std::cout << "[ type BACK to return to main menu ]" << std::endl;
	if (this->index > 7)
		index = 0;
	if (set_contact_detail(t_contact) == false)
		return ;
	_contact[this->index++] = t_contact; 
	std::cout << GREEN << "Contact added successfully" << RESET << std::endl;
}

/*
*	@brief list all the contact and search for the contact
*	@return the number of contact that want to list
*	@note 1. c_str(): string to char array
*/
void	Phonebook::SearchContact(void)
{
	std::string input;
	int nb;

	DisplayContactList();
	while (1)
	{
		std::cout << "[ type BACK to return to main menu ]" << std::endl;
		std::cout << "ENTER INDEX TO DISPLAY CONTACT [1 - 8]: ";
		std::getline(std::cin, input);
		if (check_back_or_exit(input) == false)
			return ;
		if (input.empty())
		{
			std::cout << RED << "Input cannot be empty" << RESET << std::endl;
			continue;
		}
		if (CheckDigit(input) == false)
		{
			std::cout << RED << "Only digit allow" << RESET << std::endl;
			continue;
		}
		nb = atoi(input.c_str());
		if (nb < 1 || nb > 8)
		{
			std::cout << RED << "Index out of range" << RESET << std::endl;
			continue;
		}
		get_detail(nb);
	}
}

/*****************************FUNCTION****************************************/

/*
*	@brief get the contact detail from the input
*	@param &t_contact: get the reference of the contact
*	@return TRUE: if the input is success, FALSE: if the input is fail
*/
bool Phonebook::set_contact_detail(Contact &t_contact)
{
	std::string input;

	input = check_input("Enter first name: ", false);
	if (check_back_or_exit(input) == false)
		return (false);
	t_contact.set_first_name(input);
	input = check_input("Enter last name: ", false);
	if (check_back_or_exit(input) == false)
		return (false);
	t_contact.set_last_name(input);
	input = check_input("Enter nick name: ", false);
	if (check_back_or_exit(input) == false)
		return (false);
	t_contact.set_nickname(input);
	input = check_input("Enter phone number: ", true);
	if (check_back_or_exit(input) == false)
		return (false);
	t_contact.set_phone_number(input);
	input = check_input("Enter dark secret: ", false);
	if (check_back_or_exit(input) == false)
		return (false);
	t_contact.set_dark_secret(input);
	return (true);
}

/*
*	@brief display the contact list
*/
void	Phonebook::DisplayContactList(void)
{
	int i;

	// back_door(); //for testing purpose
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "FirstName";
	std::cout << "|" << std::setw(10) << "LastName";
	std::cout << "|" << std::setw(10) << "NickName" << "|" << std::endl;
	i = 0;
	while (i < 8)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << ft_truncated(this->_contact[i]. get_first_name());
		std::cout << "|" << std::setw(10) <<ft_truncated(this->_contact[i]. get_last_name());
		std::cout << "|" << std::setw(10) << ft_truncated(this->_contact[i]. get_nickname()) << "|" << std::endl;
		i++;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

/*
*	@brief display the contact detail
*	@param index: index of the contact to display
*/
void	Phonebook::get_detail(int index)
{
	std::cout << "----------Contact ["<< index << "]----------" << std::endl;
	std::cout << "First Name: "<< this->_contact[index - 1].get_first_name() << std::endl;
	std::cout << "Last Name: "<< this->_contact[index - 1].get_last_name() << std::endl;
	std::cout << "Nick Name: "<< this->_contact[index - 1].get_nickname() << std::endl;
	std::cout << "Phone Number: "<< this->_contact[index - 1].get_phone_number() << std::endl;
	std::cout << "Dark Secret: "<< this->_contact[index - 1].get_dark_secret() << std::endl << std::endl;
}

/*
*	@brief check if the input is a digit
*	@param str: input from the user
*	@return TRUE: if the input is a digit, FALSE: if the input is not a digit
*/
bool CheckDigit(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (isdigit(str[i]) == 0 && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

/*
*	@brief function to get the input from the user
*	@param message: message to be set
*	@param HandleDigit: check if the input is a digit
*	@return input: return the input from the user input
*/
std::string check_input(std::string message, bool HandleDigit)
{
	std::string input;
	while (1)
	{
		std::cout << message;
		std::getline(std::cin, input);
		if (input == "exit")
			return ("exit");
		if (input == "back")
		{
			std::cout << RED << "Contact not added\n" << RESET;
			return ("back");
		}
		if (input.empty())
		{
			std::cout << RED << "Input cannot be empty\n" << RESET;
			continue;
		}
		if (HandleDigit == true)
		{
			if (CheckDigit(input) == false)
			{
				std::cout << RED << "Only digit allow\n" << RESET;
				continue;
			}	
		}
		break;
	}
	return (input);
}

/*
*	@brief function to truncated the string
*	@param str: string to be truncated
*	@return str: return the truncated string
*	@note: if the string is more than 10 len, then the string will be resize to 9 and add "."
*/
std::string	ft_truncated(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

/*
*	@brief check the input from the user
*	@param input: input from the user
*	@return TRUE: if the input is not "back" , FALSE: if the input is "back"
*/
bool check_back_or_exit(std::string input)
{
	if (input == "exit")
	{
		std::cout << YELLOW << "\t--EXIT PHONEBOOK--\t" << RESET << std::endl;
		exit(0);
	}
	if (input == "back")
		return (false);
	return (true);
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

// 	index = 8;
// }