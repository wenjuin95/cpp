/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:39:32 by welow             #+#    #+#             */
/*   Updated: 2024/06/01 18:39:32 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string> // std::string
#include <iostream> //input and output
#include <iomanip> // std::setw :: set width of the next input/output field
#include <cstdlib> //for atoi

# define RED "\033[0;31m"
# define GREEN "\033[1;42m"
# define YELLOW "\033[1;43m"
# define yellow "\033[0;33m"
# define RESET "\033[0m"

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
		bool set_first_name(std::string firstName);
		bool set_last_name(std::string lastName);
		bool set_nickname(std::string nickName);
		bool set_phone_number(std::string phoneNumber);
		bool set_dark_secret(std::string darkSecret);
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::string get_nickname(void) const;
		std::string get_phone_number(void) const;
		std::string get_dark_secret(void) const;
};


/*
* 	"Contact _contact[8];" is an array of 8 Contact objects
*	private: only able to access within the class not outside the class
*	EXAMPLE: _contact only able to access by "AddContact", "SearchContact"
*	         and "ReturnContact" function
*	public: able to access from outside the class and within the class
*	EXAMPLE: "AddContact" and "SearchContact" use in main.cpp
*/
class Phonebook
{
	private:
		Contact _contact[8];
	public:
		int		index;
		void	add_contact(void);
		void	search_contact(void);
		bool	set_contact_detail(Contact &t_contact);
		void	display_contact_list(void);
		void	get_detail(int index);
};

bool		check_digit(std::string str);
bool		check_only_alphanum(std::string str);
std::string	ft_truncated(std::string str);
bool		check_back_or_exit(std::string input);
bool		check_and_set_input(std::string input, Contact &t_contact,
			bool(Contact::*func)(std::string));

#endif