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

#include "Phonebook.hpp"

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

	std::cout << "====================================" << std::endl;
	std::cout << "[ type [ BACK ] to return to main menu ]" << std::endl;
	if (this->index > 7)
		index = 0;
	if (setContactDetail(t_contact) == false)
		return ;
	_contact[this->index] = t_contact;
	this->index++;
	std::cout << GREEN << "Contact added successfully" << RESET << std::endl;
}

/*
*	@brief list all the contact and search for the contact
*	@return the number of contact that want to list
*	@note 1. c_str(): string to char array
*	@note 2. atoi(): only convert char array to integer
*/
void	Phonebook::SearchContact(void)
{
	std::string input;
	int nb;

	DisplayContactList();
	while (1)
	{
		std::cout << "[ type [ BACK ] to return to main menu ]" << std::endl;
		std::cout << "ENTER INDEX TO DISPLAY CONTACT [1 - 8]: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (input.empty())
			std::cout << RED << "Input cannot be empty" << RESET << std::endl;
		else if (checkBackOrExit(input) == true)
			return ;
		else if (checkDigit(input) == false)
			continue;
		else
		{
			nb = atoi(input.c_str());
			if (nb < 1 || nb > 8)
				std::cout << RED << "Index out of range" << RESET << std::endl;
			else
				getDetail(nb);
		}
	}
}

/*****************************FUNCTION****************************************/

/**
 * @brief set the contact info
 * @param t_contact: contact to be added (make it reference because we want to change the value)
 * @return TRUE: contact added successfully, FALSE: contact not added
*/
bool Phonebook::setContactDetail(Contact &t_contact)
{
	if (checkAndSetInput("Enter first name: ", t_contact, Contact::setFirstName) == false)
		return (false);
	if (checkAndSetInput("Enter last name: ", t_contact, &Contact::setLastName) == false)
		return (false);
	if (checkAndSetInput("Enter nick name: ", t_contact, &Contact::setNickname) == false)
		return (false);
	if (checkAndSetInput("Enter phone number: ", t_contact, &Contact::setPhoneNumber) == false)
		return (false);
	if (checkAndSetInput("Enter dark secret: ", t_contact, &Contact::setDarkSecret) == false)
		return (false);
	return (true);
}

/**
 * @brief check the input from the user
 * @param msg: message to be display
 * @param t_contact: contact to be added (reference for modify the value)
 * @param func: function to be called (function pointer means which function to be called)
 *  			<datatype>(function)(parameter of the function)
 * @return TRUE: input will store in the contact, FALSE: input will not store in the contact
 *
*/
bool checkAndSetInput(std::string msg, Contact &t_contact, bool (Contact::*func)(std::string))
{
	std::string input;
	while (1)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			exit(0);
		}
		else
		if (input == "back" || input == "BACK")
		{
			std::cout << RED << "Contact not added" << RESET << std::endl;
			return (false);
		}
		else if (input == "exit" || input == "EXIT")
		{
			std::cout << YELLOW << "\t--EXIT PHONEBOOK--\t" << RESET << std::endl;
			exit(0);
		}
		else
		{
			if ((t_contact.*func)(input) == false)
				continue;
			else
				break;
		}
	}
	return (true);
}

/*
*	@brief display the contact list
*/
void	Phonebook::DisplayContactList(void)
{
	int i;

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "FirstName";
	std::cout << "|" << std::setw(10) << "LastName";
	std::cout << "|" << std::setw(10) << "NickName" << "|" << std::endl;
	i = 0;
	while (i < 8)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << truncated(this->_contact[i]. getFirstName());
		std::cout << "|" << std::setw(10) <<truncated(this->_contact[i]. getLastName());
		std::cout << "|" << std::setw(10) << truncated(this->_contact[i]. getNickname()) << "|" << std::endl;
		i++;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

/*
*	@brief display the contact detail
*	@param index: index of the contact to display
*/
void	Phonebook::getDetail(int index)
{
	std::cout << "----------Contact ["<< index << "]----------" << std::endl;
	std::cout << "First Name  :"<< this->_contact[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name   :"<< this->_contact[index - 1].getLastName() << std::endl;
	std::cout << "Nick Name   :"<< this->_contact[index - 1].getNickname() << std::endl;
	std::cout << "Phone Number:"<< this->_contact[index - 1].getPhoneNumber() << std::endl;
	std::cout << "Dark Secret :"<< this->_contact[index - 1].getDarkSecret() << std::endl << std::endl;
}

/*
*	@brief function to truncated the string
*	@param str: string to be truncated
*	@return return the truncated string
*	@note: if the string is more than 10 len, then the string will be resize to 9 and add "."
*/
std::string	truncated(std::string str)
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
*	@return TRUE: if the input is not "back" or "exit" , FALSE: if the input is "back" or "exit"
*/
bool checkBackOrExit(std::string input)
{
	if (input == "exit" || input == "EXIT")
	{
		std::cout << YELLOW << "\t--EXIT PHONEBOOK--\t" << RESET << std::endl;
		exit(0);
	}
	if (input == "back" || input == "BACK")
		return (true);
	return (false);
}
