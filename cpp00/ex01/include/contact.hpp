/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contract.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:57:37 by welow             #+#    #+#             */
/*   Updated: 2024/05/26 17:57:37 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "includelib.hpp"
/*
* class: smilar to struct in c
*
* constructor :: create an object of a class and initialize it
* default constructor :: 1. constructor with no arguments
*						 2. if no constructor is defined, the compiler provides 
*							a default constructor
*
* destuctor :: perform cleanup tasks, 
* 	 		   such as releasing resources or deallocating memory, 
* 			   associated with the object before it is destroyed
* default destructor :: 1. destructor with no arguments
*						2. if no destructor is defined, the compiler provides 
*						   a default destructor
*
* private: only able to access within the class not outside the class 
* note: to access private member, use public member function (set & get)
* EXAMPLE: _firstName only able to access by "set_first_name" 
*		   and "get_first_name" function
* 
* public: able to access from outside the class and within the class
* EXAMPLE: "set_first_name" and "get_first_name" use in main.cpp 
*/

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkSecret;
	
	public:

		//setter :: set the value of the contact
		bool set_first_name(std::string firstName);
		bool set_last_name(std::string lastName);
		bool set_nickname(std::string nickName);
		bool set_phone_number(std::string phoneNumber);
		bool set_dark_secret(std::string darkSecret);
		
		//getter :: get the value from the contact
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::string get_nickname(void) const;
		std::string get_phone_number(void) const;
		std::string get_dark_secret(void) const;
};


bool check_digit(std::string str);
bool check_only_alphanum(std::string str);

#endif