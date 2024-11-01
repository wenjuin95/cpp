/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:58:25 by welow             #+#    #+#             */
/*   Updated: 2024/05/26 17:58:25 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/******************************SETTER*****************************************/
/*
*	@brief set the first name to the private member (_firstName)
*	@param firstName: the first name of the input
*	@note 1. "this" is a pointer to the object that is calling the function
			 means get this object from the class Contact
*/ 
//<data type> <class name>::<function name>(<parameter>)
bool Contact::set_first_name(std::string firstName) 
{ 
	if (check_only_alphanum(firstName) == false)
		return (false);
	else
	{
		this->_firstName = firstName; 
		return (true);
	}
}

bool Contact::set_last_name(std::string lastName) 
{ 
	if (check_only_alphanum(lastName) == false)
		return (false);
	else
	{
		this->_lastName = lastName; 
		return (true);
	}
}

bool Contact::set_nickname(std::string nickName) 
{
	if (check_only_alphanum(nickName) == false)
		return (false);
	else
	{
		this->_nickName = nickName; 
		return (true);
	}
}

bool Contact::set_phone_number(std::string phoneNumber) 
{ 
	if (check_only_alphanum(phoneNumber) == false)
		return (false);
	else if (check_digit(phoneNumber) == false)
		return (false);
	else if (phoneNumber.length() != 10)
	{
		std::cout << RED << "Phone number must be 10 digits\n" << RESET;
		return (false);
	}
	else
	{
		this->_phoneNumber = phoneNumber; 
		return (true);
	}
}

bool Contact::set_dark_secret(std::string darkSecret)
{ 
	if (darkSecret.empty() || darkSecret == " ")
	{
		std::cout << RED << "Cannot be empty\n" << RESET;
		return (false);
	}
	else
	{
		this->_darkSecret = darkSecret; 
		return (true);
	}
}

/*******************************GETTER****************************************/
/*
*	@brief get the first name from the private member (_firstName)
*	@return the first name of the contact
*	@note 1. "const" keyword is used to make sure the function does not modify the object and just read
*/
std::string Contact::get_first_name(void) const { return (this->_firstName); }

std::string Contact::get_last_name(void) const { return (this->_lastName); }

std::string Contact::get_nickname(void) const { return (this->_nickName); }

std::string Contact::get_phone_number(void) const { return (_phoneNumber); }

std::string Contact::get_dark_secret(void) const { return (_darkSecret); }

/**
 * @brief check if the string is digit
 * @param str string to check
 * @return true if the string is digit, false for not string
*/
bool check_digit(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (isdigit(str[i]) == 0)
		{
			std::cout << RED << "Only digit allow\n" << RESET;
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * @brief check only alphabet and number allow
 * @param str string to check
 * @return true if the string is alphabet and number, false for not alphabet and number
 * 
*/
bool check_only_alphanum(std::string str)
{
	int	i;

	i = 0;
	if (str.empty() || str == " ")
	{
		std::cout << RED << "Cannot be empty\n" << RESET;
		return (false);
	}
	while (str[i])
	{
		if (isalnum(str[i]) == 0)
		{
			std::cout << RED << "Only alphabet/number allow\n" << RESET;
			return (false);
		}
		i++;
	}
	return (true);
}