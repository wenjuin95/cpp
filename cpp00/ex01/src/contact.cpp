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
	_firstName = "";
	_lastName = "";
	_nickName = "";
	_phoneNumber = "";
	_darkSecret = "";
}

Contact::~Contact(void) {}

/******************************************SETTER***************************************************************/
void Contact::set_first_name(std::string fn)
{
	if (check_alpha(fn) == FALSE)
	{
		std::cout << "Only alphabet allow" << std::endl;
		return ;
	}
	else
		_firstName = fn;
}

void Contact::set_last_name(std::string ln)
{
	if (check_alpha(ln) == FALSE)
	{
		std::cout << "Only alphabet allow" << std::endl;
		return ;
	}
	else
		_lastName = ln;
}

void Contact::set_nickname(std::string nn)
{
	if (check_alpha(nn) == FALSE)
	{
		std::cout << "Only alphabet allow" << std::endl;
		return ;
	}
	else
		_nickName = nn;
}

void Contact::set_phone_number(std::string pn)
{
	if (check_digit(pn) == FALSE)
	{
		std::cout << "Only digit allow" << std::endl;
		return ;
	}
	else
		_phoneNumber = pn;
}

void Contact::set_dark_secret(std::string ds)
{

	_darkSecret = ds;
}

/******************************************GETTER***************************************************************/
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

/******************************************FUNCTION***************************************************************/
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

// void	Contact::print_contact(void)
// {
// 	std::cout << "|" << std::setw(15) << _firstName;
// 	std::cout << "|" << std::setw(15) << _lastName;
// 	std::cout << "|" << std::setw(15) << _nickName;
// 	std::cout << "|" << std::setw(15) << _phoneNumber;
// 	std::cout << "|" << std::setw(15) << _darkSecret;
// 	std::cout << "|" << std::endl;
// }