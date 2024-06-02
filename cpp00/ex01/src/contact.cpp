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

//default constructor
Contact::Contact() {}

/* 
* destuctor :: purpose is to perform cleanup tasks, 
* 	 		   such as releasing resources or deallocating memory, 
* 			   associated with the object before it is destroyed
*/
Contact::~Contact() {}

Contact::set_first_name(std::string fn)
{
	fn = first_name;
}

Contact::set_last_name(std::string ln)
{
	ln = last_name;
}

Contact::set_nickname(std::string nn)
{
	nn = nickname;
}

Contact::set_phone_number(int pn)
{
	pn = phone_number;
}

Contact::set_dark_secret(std::string ds)
{
	ds = dark_secret;
}

Contact::get_first_name()
{
	return (first_name);
}

Contact::get_last_name()
{
	return (last_name);
}

Contact::get_nickname()
{
	return (nickname);
}

Contact::get_phone_number()
{
	return (phone_number);
}

Contact::get_dark_secret()
{
	return (dark_secret);
}

Contact::print_contact()
{
	std::cout << "First Name: " << first_name << "\n";
	std::cout << "Last Name: " << last_name << "\n";
	std::cout << "Nickname: " << nickname << "\n";
	std::cout << "Phone Number: " << phone_number << "\n";
	std::cout << "Dark Secret: " << dark_secret << "\n";
}