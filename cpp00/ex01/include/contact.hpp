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

#include <iostream>

/*
* class: smilar to struct in c
*
* important for default constructor:
* 1. Initialization: This avoids any undefined or unexpected state.
* 2. Consistency: Ensures that every Car object starts in a consistent and 
*	 predictable state, improving code reliability and readability.
* 3. Safety: Helps prevent bugs related to uninitialized member variables, 
*	 especially for built-in types like int, where uninitialized variables 
*	 can lead to undefined behavior.
*
* destuctor :: purpose is to perform cleanup tasks, 
* 	 		   such as releasing resources or deallocating memory, 
* 			   associated with the object before it is destroyed
*/

//Contact :: get & print contact information
/*
* 1. first & last name
* 2. nickname
* 3. phone number
* 4. dark secret is a secret word (optional)
*/
class Contact
{
	private
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string	dark_secret;
		int			phone_number;
	public:
		Contact(); //default constructor
		~Contact(); //destructor

		//setter :: set the value of the contact
		void set_first_name(std::string first_name);
		void set_last_name(std::string last_name);
		void set_nickname(std::string nickname);
		void set_phone_number(int phone_number);
		void set_dark_secret(std::string dark_secret);
		
		//getter :: get the value from the contact
		std::string get_first_name();
		std::string get_last_name();
		std::stirng get_nickname();
		int get_phone_number();
		std::string get_dark_secret();
		
		//print contact
		void print_contact();
};

#endif