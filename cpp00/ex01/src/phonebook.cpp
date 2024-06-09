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
	// backdoor();
}

Phonebook::~Phonebook(void) {}

//function to add contact
void	Phonebook::add_contact(void)
{
	if (_index > 7)
		_index = 0;
	std::string input;
	Contact t_contact; //temporary contact
	while (1)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input); // get the input from the user and assign to input
		if (std::cin.eof()) // if the user press ctrl + D then return to main
		{
			std::cin.clear(); //clear the buffer
      		clearerr(stdin);  //clear the error
      		return;
		}
		if (input.empty()) 
		{
			std::cout << RED << "first name cannot be empty\n" << RESET;
			continue;
		}
		else
		{
			if (t_contact.check_alpha(input) == FALSE)
			{
				std::cout << RED << "Only alphabet allow\n" << RESET;
				continue;
			}
			else
			{
				t_contact.set_first_name(input);
				// std::cout << _contact[_index].get_first_name() << std::endl; //debug
				break ;
			}
		}	
	}

	while (1)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) // if the user press ctrl + D then return to main
		{
			std::cin.clear(); //clear the buffer
      		clearerr(stdin);  //clear the error
      		return;
		}
		if (input.empty())
		{
			std::cout << RED << "last name cannot be empty\n" << RESET;
			continue;
		}
		else
		{
			if (t_contact.check_alpha(input) == FALSE)
			{
				std::cout << RED << "Only alphabet allow\n" << RESET;
				continue;
			}
			else
			{
				t_contact.set_last_name(input);
				// std::cout << _contact[_index].get_last_name() << std::endl; //debug
				break ;
			}
		}	
	}

	while (1)
	{
		std::cout << "Enter nick name: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) // if the user press ctrl + D then return to main
		{
			std::cin.clear(); //clear the buffer
      		clearerr(stdin);  //clear the error
      		return;
		}
		if (input.empty())
		{
			std::cout << RED << "nick name cannot be empty\n" << RESET;
			continue;
		}
		else
		{
			if (t_contact.check_alpha(input) == FALSE)
			{
				std::cout << RED << "Only alphabet allow\n" << RESET;
				continue;
			}
			else
			{
				t_contact.set_nickname(input);
				// std::cout << _contact[_index].get_nickname() << std::endl; //debug
				break ;
			}
		}	
	}

	while (1)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) // if the user press ctrl + D then return to main
		{
			std::cin.clear(); //clear the buffer
      		clearerr(stdin);  //clear the error
      		return;
		}
		if (input.empty())
		{
			std::cout << RED << "phone number cannot be empty\n" << RESET;
			continue;
		}
		else
		{
			if (t_contact.check_digit(input) == FALSE)
			{
				std::cout << RED << "Only digit allow\n" << RESET;
				continue;
			}
			else
			{
				t_contact.set_phone_number(input);
				// std::cout << _contact[_index].get_phone_number() << std::endl; //debug
				break ;
			}
		}	
	}

	while (1)
	{
		std::cout << "Enter dark secret: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) // if the user press ctrl + D then return to main
		{
			std::cin.clear(); //clear the buffer
      		clearerr(stdin);  //clear the error
      		return;
		}
		if (input.empty())
		{
			std::cout << RED << "dark secret cannot be empty\n" << RESET;
			continue;
		}
		else
		{
			if (t_contact.check_alpha(input) == FALSE)
			{
				std::cout << RED << "Only alphabet allow\n" << RESET;
				continue;
			}
			else
			{
				t_contact.set_dark_secret(input);
				// std::cout << _contact[_index].get_dark_secret() << std::endl; //debug
				break ;
			}
		}	
	}

	_contact[_index++] = t_contact; //assign the temporary contact to the contact and index increment
	std::cout << GREEN << "Contact added successfully\n" << RESET;
}

//function to show contact (debug use)
// void	Phonebook::display_contact(void)
// {
// 	std::cout << "|" << "No.";
// 	std::cout << "|" << std::setw(10) << "FirstName";
// 	std::cout << "|" << std::setw(10) << "LastName";
// 	std::cout << "|" << std::setw(10) << "NickName";
// 	std::cout << "|" << std::setw(10) << "Phone";
// 	std::cout << "|" << std::setw(10) << "Secret" << "|" << std::endl;
// 	for (int i = 0; i < 8; i++)
// 	{
// 		std::cout << "|" << std::setw(3) << i;
// 		std::cout << "|" << std::setw(10) << _contact[i]. get_first_name();
// 		std::cout << "|" << std::setw(10) << _contact[i]. get_last_name();
// 		std::cout << "|" << std::setw(10) << _contact[i]. get_nickname();
// 		std::cout << "|" << std::setw(10) << _contact[i]. get_phone_number();
// 		std::cout << "|" << std::setw(10) << _contact[i]. get_dark_secret();
// 		std::cout << "|" << std::endl;
// 	}
// }



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