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

#include "Contact.hpp"

/******************************SETTER*****************************************/
/*
*	@brief set the first name to the private member (_firstName)
*	@param firstName: the first name of the input
*	@note 1. "this" is a pointer to the object that is calling the function
			 means get this object from the class Contact
*/
//<data type> <class name>::<function name>(<parameter>)
bool Contact::setFirstName(std::string firstName)
{
	if (checkOnlyAlphanum(firstName) == false)
		return (false);
	else
	{
		this->_firstName = firstName;
		return (true);
	}
}

bool Contact::setLastName(std::string lastName)
{
	if (checkOnlyAlphanum(lastName) == false)
		return (false);
	else
	{
		this->_lastName = lastName;
		return (true);
	}
}

bool Contact::setNickname(std::string nickName)
{
	if (checkOnlyAlphanum(nickName) == false)
		return (false);
	else
	{
		this->_nickName = nickName;
		return (true);
	}
}

bool Contact::setPhoneNumber(std::string phoneNumber)
{
	if (checkOnlyAlphanum(phoneNumber) == false)
		return (false);
	else if (checkDigit(phoneNumber) == false)
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

bool Contact::setDarkSecret(std::string darkSecret)
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
std::string Contact::getFirstName(void) const { return (this->_firstName); }

std::string Contact::getLastName(void) const { return (this->_lastName); }

std::string Contact::getNickname(void) const { return (this->_nickName); }

std::string Contact::getPhoneNumber(void) const { return (_phoneNumber); }

std::string Contact::getDarkSecret(void) const { return (_darkSecret); }

/**
 * @brief check if the string is digit
 * @param str string to check
 * @return true if the string is digit, false for not string
*/
bool checkDigit(std::string str)
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
bool checkOnlyAlphanum(std::string str)
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
