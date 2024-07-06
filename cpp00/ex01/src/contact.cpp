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

Contact::Contact(void)
{
	// std::cout << yellow << "Contact created" << RESET << std::endl;
}

Contact::~Contact(void)
{
	// std::cout << yellow << "Contact destroyed" << RESET << std::endl;
}

/******************************SETTER*****************************************/
// "this" is a pointer to the object that is calling the function (mean this object)
void Contact::set_first_name(std::string firstName)
{
	this->_firstName = firstName;
}

void Contact::set_last_name(std::string lastName)
{
	this->_lastName = lastName;
}

void Contact::set_nickname(std::string nickName)
{
	this->_nickName = nickName;
}

void Contact::set_phone_number(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::set_dark_secret(std::string darkSecret)
{
	this->_darkSecret = darkSecret;
}

/*******************************GETTER****************************************/
std::string Contact::get_first_name(void)
{
	return (_firstName);
}

std::string Contact::get_last_name(void)
{
	return (_lastName);
}

std::string Contact::get_nickname(void)
{
	return (_nickName);
}

std::string Contact::get_phone_number(void)
{
	return (_phoneNumber);
}

std::string Contact::get_dark_secret(void)
{
	return (_darkSecret);
}

