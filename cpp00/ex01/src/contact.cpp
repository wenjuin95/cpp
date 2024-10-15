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

/*
*	@brief create a contact constructor
*/
Contact::Contact(void)
{
	std::cout << yellow << "Contact created" << RESET << std::endl;
}

/*
*	@brief create a contact destructor
*/
Contact::~Contact(void)
{
	std::cout << yellow << "Contact destroyed" << RESET << std::endl;
}

/******************************SETTER*****************************************/
/*
*	@brief set the first name to the private member (_firstName)
*	@param firstName: the first name of the input
*	@note 1. "this" is a pointer to the object that is calling the function
			 means get this object from the class Contact
*/ 
//<data type> <class name>::<function name>(<parameter>)
void Contact::set_first_name(std::string firstName) { this->_firstName = firstName; }

void Contact::set_last_name(std::string lastName) { this->_lastName = lastName; }

void Contact::set_nickname(std::string nickName) { this->_nickName = nickName; }

void Contact::set_phone_number(std::string phoneNumber) { this->_phoneNumber = phoneNumber; }

void Contact::set_dark_secret(std::string darkSecret) { this->_darkSecret = darkSecret; }

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

