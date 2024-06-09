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

/*****************************CONSTRUCTOR*************************************/
//this constructor is for phonebook class to use
Contact::Contact(void) {}

/* ****************************DESTRUCTOR*************************************/
//this destructor is for phonebook class to use
Contact::~Contact(void) {}

/******************************SETTER*****************************************/
void Contact::set_first_name(std::string fn)
{
	_firstName = fn;
}

void Contact::set_last_name(std::string ln)
{
	_lastName = ln;
}

void Contact::set_nickname(std::string nn)
{
	_nickName = nn;
}

void Contact::set_phone_number(std::string pn)
{
	_phoneNumber = pn;
}

void Contact::set_dark_secret(std::string ds)
{

	_darkSecret = ds;
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

/***************************FUNCTION*****************************************/
int Contact::check_alpha(std::string str)
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

int Contact::check_digit(std::string str)
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
