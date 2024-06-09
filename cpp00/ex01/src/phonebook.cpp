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

Phonebook::Phonebook(void)
{
	_index = 0;
}

Phonebook::~Phonebook(void) {}

void	Phonebook::add_contact(void)
{
	_index++;
	if (_index > 7)
		_index = 0;
	while (1)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, _contact[_index].first_name);
		if (_contact[_index].first_name.empty())
		{
			std::cout << "First name cannot be empty!" << std::endl;
			continue;
		}
		else
			set_first_name(_contact[_index].first_name);
		std::cout << "Enter last name: ";
		std::getline(std::cin, _contact[_index].last_name);
		if (_contact[_index].last_name.empty())
		{
			std::cout << "Last name cannot be empty!" << std::endl;
			continue;
		}
		else
			set_last_name(_contact[_index].last_name);
		std::cout << "Enter nickname: ";
		std::getline(std::cin, _contact[_index].nick_name);
		if (_contact[_index].nick_name.empty())
		{
			std::cout << "Nickname cannot be empty!" << std::endl;
			continue;
		}
		else
			set_nickname(_contact[_index].nick_name);
		std::cout << "Enter phone number: ";
		std::getline(std::cin, _contact[_index].phone_number);
		if (_contact[_index].phone_number.empty())
		{
			std::cout << "Phone number cannot be empty!" << std::endl;
			continue;
		}
		else
			set_phone_number(_contact[_index].phone_number);
		std::cout << "Enter dark secret: ";
		std::getline(std::cin, _contact[_index].dark_secret);
		if (_contact[_index].dark_secret.empty())
		{
			std::cout << "Dark secret cannot be empty!" << std::endl;
			continue;
		}
		else
			set_dark_secret(_contact[_index].dark_secret);
		std::cout << "Contact added!" << std::endl;
		break;
	}
}

void	Contact::display_contact(void)
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << _contact[i].first_name << "|";
		std::cout << std::setw(10) << _contact[i].last_name << "|";
		std::cout << std::setw(10) << _contact[i].nick_name << "|" << std::endl;
	}
}