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

#include <string> // std::string
/*
* class: smilar to struct in c
*
* constructor :: purpose is to initialize the object of the class
* default constructor :: 1. constructor with no arguments
*						 2. if no constructor is defined, the compiler provides 
*							a default constructor
*
* destuctor :: purpose is to perform cleanup tasks, 
* 	 		   such as releasing resources or deallocating memory, 
* 			   associated with the object before it is destroyed
* default destructor :: 1. destructor with no arguments
*						2. if no destructor is defined, the compiler provides 
*						   a default destructor
*
* private :: not allow to access from outside the class
* note: to access private member, use public member function (set & get)
* 
* public :: allow to access from outside the class
* note: to access public member, use object of the class
*/

/*
* contact information consist of:
* 1. first & last name
* 2. nickname
* 3. phone number
* 4. dark secret is a secret word (optional)
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
		Contact(void); // default constructor myself
		~Contact(void); // because you create a constructor, you need to create a destructor
	
		//setter :: set the value of the contact
		void set_first_name(std::string firstName);
		void set_last_name(std::string lastName);
		void set_nickname(std::string nickName);
		void set_phone_number(std::string phoneNumber);
		void set_dark_secret(std::string darkSecret);
		
		//getter :: get the value from the contact
		std::string get_first_name(void);
		std::string get_last_name(void);
		std::string get_nickname(void);
		std::string get_phone_number(void);
		std::string get_dark_secret(void);
};

#endif