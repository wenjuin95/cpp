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
