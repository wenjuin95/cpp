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
* private: only able to access within the class not outside the class
* EXAMPLE: you can set the private member of the class 
*		   by using public member function 
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
		bool setFirstName(std::string firstName);
		bool setLastName(std::string lastName);
		bool setNickname(std::string nickName);
		bool setPhoneNumber(std::string phoneNumber);
		bool setDarkSecret(std::string darkSecret);
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkSecret(void) const;
};


bool checkDigit(std::string str);
bool checkOnlyAlphanum(std::string str);

#endif